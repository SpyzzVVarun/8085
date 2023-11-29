// This file is part of an 8085 emulator project.
// It contains the implementation of the validityRegisters function.

#include "header/global.h"

// Function to check the validity of a register name.
bool validityRegisters(string reg)
{
    // Check if the register name is valid.
    if(reg=="A"||reg=="B"||reg=="C"||reg=="D"||reg=="E"||reg=="H"||reg=="L")
        return true;
    else
        return false;
}