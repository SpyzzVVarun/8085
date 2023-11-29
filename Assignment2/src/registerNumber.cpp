// This file is part of an 8085 emulator project.
// It contains the implementation of the registerNumber() function.

#include "global.h"

// This function takes a string representing a register name (A, B, C, D, E, H, L)
// and returns the corresponding register number.
int registerNumber(string str)
{
    if(str=="A")
        return 0;
    if(str=="B")
        return 1;
    if(str=="C")
        return 2;
    if(str=="D")
        return 3;
    if(str=="E")
        return 4;
    if(str=="H")
        return 5;
    if(str=="L")
        return 6;
    
    // If the input string does not match any register name, return 0.
    return 0;
}