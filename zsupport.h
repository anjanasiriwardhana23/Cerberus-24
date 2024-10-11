#ifndef ZSUPPORT_H
#define ZSUPPORT_H

#include <Arduino.h>  // Include Arduino library for Serial functions
#include "zvariables.h"

// Assuming 14x14 grid for cells, flood, and flood2 arrays (adjust size if needed)
//extern int cells[14][14];   // Declare external 2D array for cells
//extern int flood[14][14];   // Declare external 2D array for flood
//extern int flood2[14][14];  // Declare external 2D array for flood2

// Function prototypes for printing grid data
void showCells();     // Function to print the cells array
void showFlood();     // Function to print the flood array
void showFlood2();    // Function to print the flood2 array

#endif  // ZSUPPORT_H