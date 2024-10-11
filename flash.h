#ifndef FLASH_H
#define FLASH_H

#include <Arduino.h>
#include <LittleFS_Mbed_RP2040.h>
#include "zvariables.h"

// Define LittleFS configuration for RP2040
#define LFS_MBED_RP2040_VERSION_MIN_TARGET      "LittleFS_Mbed_RP2040 v1.1.0"
#define LFS_MBED_RP2040_VERSION_MIN             1001000

#define _LFS_LOGLEVEL_          1
#define RP2040_FS_SIZE_KB 256  // Increase LittleFS filesystem to 128KB
#define FORCE_REFORMAT true    // Force reformat to apply new size

#define ARRAY_SIZE 16  // Define the size of the 2D array (16x16)
#define CELL_SIZE 14
#define FILE_PATH "/cells.dat"
//#define FILE_PATH "/cells.dat"

extern LittleFS_MBED *myFS;  // File system object

// Function declarations for file operations
void readCharsFromFile(const char * path);    // Read characters from file and print
void readFile(const char * path);             // Read and print file content
void writeFile(const char * path, const char * message, size_t messageSize);  // Write to file
void appendFile(const char * path, const char * message, size_t messageSize); // Append to file
void deleteFile(const char * path);           // Delete a file
void renameFile(const char * path1, const char * path2); // Rename a file
void testFileIO(const char * path);           // Test File I/O by reading/writing large data

// LittleFS Initialization function
bool initFileSystem();                        // Initialize LittleFS filesystem

// New functions to handle the 16x16 array
void writeArrayToFile(const char* path, byte array[ARRAY_SIZE][ARRAY_SIZE]);  // Write 16x16 array to file
void readArrayFromFile(const char* path, byte array[ARRAY_SIZE][ARRAY_SIZE]); // Read 16x16 array from file
void writeCellsToFile(const char* path, byte cells[CELL_SIZE][CELL_SIZE]);
void readCellsFromFile(const char* path, byte cells[CELL_SIZE][CELL_SIZE]);

//void testBasicFileSystem();

#endif // FLASH_H
