#include "Flash.h"
#include "zvariables.h"

LittleFS_MBED* myFS;

// Initialize the filesystem

bool initFileSystem() {
    myFS = new LittleFS_MBED();
    if (!myFS->init()) {
        Serial.println("LITTLEFS Mount Failed");
        return false;
    }
    Serial.println("LITTLEFS Mount Successful");
    return true;
}

void readCharsFromFile(const char * path) {
    Serial.print("readCharsFromFile: "); Serial.print(path);

    FILE *file = fopen(path, "r");

    if (file) {
        Serial.println(" => Open OK");
    } else {
        Serial.println(" => Open Failed");
        return;
    }

    char c;
    while (true) {
        c = fgetc(file);
        if (feof(file)) {
            break;
        } else {
            Serial.print(c);
        }
    }
    fclose(file);
}

void readFile(const char * path) {
    Serial.print("Reading file: "); Serial.print(path);

    FILE *file = fopen(path, "r");

    if (file) {
        Serial.println(" => Open OK");
    } else {
        Serial.println(" => Open Failed");
        return;
    }

    char c;
    uint32_t numRead = 1;

    while (numRead) {
        numRead = fread((uint8_t *) &c, sizeof(c), 1, file);
        if (numRead) Serial.print(c);
    }
    fclose(file);
}

void writeFile(const char * path, const char * message, size_t messageSize) {
    Serial.print("Writing file: "); Serial.print(path);

    FILE *file = fopen(path, "w");

    if (file) {
        Serial.println(" => Open OK");
    } else {
        Serial.println(" => Open Failed");
        return;
    }

    if (fwrite((uint8_t *) message, 1, messageSize, file)) {
        Serial.println("* Writing OK");
    } else {
        Serial.println("* Writing failed");
    }

    fclose(file);
}

void appendFile(const char * path, const char * message, size_t messageSize) {
    Serial.print("Appending file: "); Serial.print(path);

    FILE *file = fopen(path, "a");

    if (file) {
        Serial.println(" => Open OK");
    } else {
        Serial.println(" => Open Failed");
        return;
    }

    if (fwrite((uint8_t *) message, 1, messageSize, file)) {
        Serial.println("* Appending OK");
    } else {
        Serial.println("* Appending failed");
    }
    fclose(file);
}

void deleteFile(const char * path) {
    Serial.print("Deleting file: "); Serial.print(path);

    if (remove(path) == 0) {
        Serial.println(" => OK");
    } else {
        Serial.println(" => Failed");
    }
}

void renameFile(const char * path1, const char * path2) {
    Serial.print("Renaming file: "); Serial.print(path1);
    Serial.print(" to: "); Serial.print(path2);

    if (rename(path1, path2) == 0) {
        Serial.println(" => OK");
    } else {
        Serial.println(" => Failed");
    }
}

// Function to write a 16x16 array to the flash memory
void writeArrayToFile(const char* path, byte array[ARRAY_SIZE][ARRAY_SIZE]) {
    FILE* file = fopen(path, "w");
    if (!file) {
        Serial.println("Failed to open file for writing");
        return;
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (fwrite(array[i], sizeof(byte), ARRAY_SIZE, file) != ARRAY_SIZE) {
            Serial.println("Failed to write data");
            fclose(file);
            return;
        }
    }

    Serial.println("Array written to file successfully.");
    fclose(file);
}

// Function to read a 16x16 array from flash memory
void readArrayFromFile(const char* path, byte array[ARRAY_SIZE][ARRAY_SIZE]) {
    FILE* file = fopen(path, "r");
    if (!file) {
        Serial.println("Failed to open file for reading");
        return;
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (fread(array[i], sizeof(byte), ARRAY_SIZE, file) != ARRAY_SIZE) {
            Serial.println("Failed to read data");
            fclose(file);
            return;
        }
    }

    Serial.println("Array read from file successfully.");
    fclose(file);
}

void testFileIO(const char * path) {
    Serial.print("Testing file I/O with: "); Serial.print(path);

    #define BUFF_SIZE 512

    static uint8_t buf[BUFF_SIZE];

    FILE *file = fopen(path, "w");

    if (file) {
        Serial.println(" => Open OK");
    } else {
        Serial.println(" => Open Failed");
        return;
    }

    size_t i;
    Serial.println("- writing");

    uint32_t start = millis();

    size_t result = 0;

    for (i = 0; i < RP2040_FS_SIZE_KB / 2; i++) {
        result = fwrite(buf, BUFF_SIZE, 1, file);

        if (result != 1) {
            Serial.print("Write result = "); Serial.println(result);
            Serial.print("Write error, i = "); Serial.println(i);
            break;
        }
    }

    Serial.println("");
    uint32_t end = millis() - start;

    Serial.print(i / 2);
    Serial.print(" Kbytes written in (ms) ");
    Serial.println(end);

    fclose(file);

    file = fopen(path, "r");

    start = millis();
    end = start;
    i = 0;

    if (file) {
        start = millis();
        Serial.println("- reading");

        result = 0;

        fseek(file, 0, SEEK_SET);

        for (i = 0; i < RP2040_FS_SIZE_KB / 2; i++) {
            result = fread(buf, BUFF_SIZE, 1, file);

            if (result != 1) {
                Serial.print("Read result = "); Serial.println(result);
                Serial.print("Read error, i = "); Serial.println(i);
                break;
            }
        }

        Serial.println("");
        end = millis() - start;

        Serial.print((i * BUFF_SIZE) / 1024);
        Serial.print(" Kbytes read in (ms) ");
        Serial.println(end);

        fclose(file);
    } else {
        Serial.println("- failed to open file for reading");
    }
}

void writeCellsToFile(const char* path, byte cells[CELL_SIZE][CELL_SIZE]) {
    FILE* file = fopen(path, "w");
    if (!file) {
        Serial.println("Failed to open file for writing");
        return;
    }

    for (int i = 0; i < CELL_SIZE; i++) {
        if (fwrite(cells[i], sizeof(byte), CELL_SIZE, file) != CELL_SIZE) {
            Serial.println("Failed to write data");
            fclose(file);
            return;
        }
    }

    Serial.println("Cells written to file successfully.");
    fclose(file);
}

void readCellsFromFile(const char* path, byte cells[CELL_SIZE][CELL_SIZE]) {
    FILE* file = fopen(path, "r");
    if (!file) {
        Serial.println("Failed to open file for reading");
        return;
    }

    for (int i = 0; i < CELL_SIZE; i++) {
        if (fread(cells[i], sizeof(byte), CELL_SIZE, file) != CELL_SIZE) {
            Serial.println("Failed to read data");
            fclose(file);
            return;
        }
    }

    Serial.println("Cells read from file successfully.");
    fclose(file);
}

/*
void loadCells() {
    FILE* file = fopen("/cellsData.txt", "r");
    if (!file) {
        Serial.println("Failed to open file for reading");
        return;
    }

    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 14; j++) {
            if (fread(&cells[j][i], sizeof(byte), 1, file) != 1) {
                Serial.println("Failed to read cell data");
                fclose(file);
                return;
            }
        }
    }

    Serial.println("Cells loaded successfully.");
    fclose(file);
}

void writeCells() {
    const char* fileName = MBED_LITTLEFS_FILE_PREFIX "/cellsData.txt";
    FILE* file = fopen(fileName, "w");
    if (!file) {
        Serial.println("Failed to open file for writing");
        return;
    }

    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 14; j++) {
            if (fwrite(&cells[j][i], sizeof(byte), 1, file) != 1) {
                Serial.println("Failed to write cell data");
                fclose(file);
                return;
            }
        }
    }

    Serial.println("Cells written successfully.");
    fclose(file);
}

void testBasicFileSystem() {
    if (initFileSystem()) {
        FILE *file = fopen("/simpleTest.txt", "w");
        if (file) {
            Serial.println("File opened successfully for writing");
            const char *data = "Test data";
            fwrite(data, sizeof(char), strlen(data), file);
            fclose(file);
            Serial.println("File written successfully");
        } else {
            Serial.println("Failed to open file for writing");
        }
    }
}
*/