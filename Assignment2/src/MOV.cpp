// This file, MOV.cpp, is part of an 8085 emulator project.
// It contains the implementation of the MOV instruction, which is used to move data between registers and memory.

#include "header/global.h" 
#include "header/tools.h"

// Implementation of the MOV instruction.
void MOV(string argument1, string argument2, string registers[], bool flag[], map<string, string> &memory)
{
    if (argument1 == "M" && argument2 != "M") {
        // If the first argument is "M" and the second argument is a valid register, move the data from the register to memory.
        string address = registers[5] + registers[6]; // Get the memory address from the HL register pair.
        memory[address] = registers[registerNumber(argument2)]; // Move the data from the register to the memory location.
    }
    else if (argument1 != "M" && argument2 == "M") {
        // If the first argument is a valid register and the second argument is "M", move the data from memory to the register.
        string address = registers[5] + registers[6]; // Get the memory address from the HL register pair.
        registers[registerNumber(argument1)] = memory[address]; // Move the data from the memory location to the register.
    }
    else if (argument1 != "M" && argument2 != "M") {
        // If both arguments are valid registers, move the data from one register to another.
        registers[registerNumber(argument1)] = registers[registerNumber(argument2)]; // Move the data from one register to another.
    }
}