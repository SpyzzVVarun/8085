// This file, MOV.cpp, is part of an 8085 emulator project.
// It contains the implementation of the MOV instruction, which is used to move data between registers and memory.

#include "global.h" 
#include "tools.h"

// Implementation of the MOV instruction.
void MOV(string argument1, string argument2, string registers[], bool flag[], map<string, string> &memory)
{
    int l1 = argument1.length(); // Get the length of the first argument.
    int l2 = argument2.length(); // Get the length of the second argument.

    // Check if both arguments are single characters.
    if (l1 == 1 && l2 == 1) {
        if (argument1 == "M" && argument2 != "M" && validityRegisters(argument2)) {
            // If the first argument is "M" and the second argument is a valid register, move the data from the register to memory.
            string address = registers[5] + registers[6]; // Get the memory address from the HL register pair.
            memory[address] = registers[registerNumber(argument2)]; // Move the data from the register to the memory location.
        }
        else if (argument1 != "M" && argument2 == "M" && validityRegisters(argument1)) {
            // If the first argument is a valid register and the second argument is "M", move the data from memory to the register.
            string address = registers[5] + registers[6]; // Get the memory address from the HL register pair.
            registers[registerNumber(argument1)] = memory[address]; // Move the data from the memory location to the register.
        }
        else if (argument1 != "M" && argument2 != "M" && validityRegisters(argument2) && validityRegisters(argument1)) {
            // If both arguments are valid registers, move the data from one register to another.
            registers[registerNumber(argument1)] = registers[registerNumber(argument2)]; // Move the data from one register to another.
        }
        else {
            // If the arguments are invalid, display an error message and exit the program.
            cout << "Error: Invalid content\nThe program will quit\n";
            exit(0);
        }
    }
}