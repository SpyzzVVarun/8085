// This file is a part of an 8085 emulator project.
// It contains the implementation of the updatedAddress function, which is responsible for updating the memory address in the emulator.

#include "global.h"
#include "tools.h"

string updatedAddress(string PC, map<string, string>& Memory) {
    string command = Memory[PC];
    string opcode;

    // Check if the command is HLT, XCHG, or CMA
    // If yes, set the opcode to the command itself
    if (command == "HLT" || command == "XCHG" || command == "CMA") {
        opcode = command;
    }
    else {
        // Split the command into tokens using delimiter " ,"
        const char* partition = command.c_str();
        char* temporary = (char*)partition;
        const char* delimiter = " ,";
        char* part = strtok(temporary, delimiter);
        opcode = part;
    }

    // Get the size of the operation based on the opcode
    int n = operationSize(opcode);
    string result;

    // Update the memory address 'n' times
    for (int j = 1; j <= n; j++) {
        int array[4] = { -1, -1, -1, -1 };
        result = "";

        // Convert the current PC value from hexadecimal to decimal
        hexToDecimal(PC, array);

        int i = 3;
        array[i] += 1;

        // Carry propagation for hexadecimal addition
        while (array[i] >= 16) {
            array[i] = array[i] % 16;
            array[i - 1]++;
            i--;
        }

        // Convert the decimal array back to hexadecimal string
        for (int i = 0; i < 4; i++) {
            if (array[i] >= 0 && array[i] <= 9)
                result = result + char('0' + array[i]);
            else
                result = result + char('A' + (array[i] - 10));
        }

        // Update the memory with the current command at the new address
        Memory[result] = Memory[PC];
        PC = result;
    }

    return PC;
}