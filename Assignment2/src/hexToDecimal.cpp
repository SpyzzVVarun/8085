// This file is part of an 8085 emulator project.
// It contains a function to convert a hexadecimal string to decimal and store the result in an array.

#include "header/global.h"
#include <string>

void hexToDecimal(string pc, int arr[]) {
    int l = pc.length();
    int p = 0;
    
    // Iterate through each character of the hexadecimal string
    for (int i = 0; i < l; i++) {
        // If the character is a digit (0-9), convert it to decimal and store in the array
        if (pc[i] >= '0' && pc[i] <= '9')
            arr[i] = pc[i] - '0';
        // If the character is a letter (A-F), convert it to decimal and store in the array
        else 
            arr[i] = 10 + (pc[i] - 'A'); 
    }
}