/* 
   This file is part of an 8085 emulator project.
   It contains the implementation of the operationSize function,
   which takes a complete command as input, breaks it into operand and opcode,
   and checks the size of the command.
*/


#include "header/global.h"

int operationSize(string str){

    // Arrays to store different types of commands
    string one[] = {"HLT","MOV","STAX","XCHG","ADD","SUB","INR","DCR","INX","DCX","DAD","CMA","CMP"};
    string two[] = {"MVI","ADI","SUI"};
    string three[] = {"LXI","LDA","STA","SHLD","LHLD","JMP","JC","JNZ","JNC","JZ","SET"};

    // Convert the input string to a character array
    const char *ch = str.c_str();
    char *var = (char*)ch;

    // Tokenize the input string using delimiter " ,"
    const char *delimiter = " ,";
    char *pch = strtok (var,delimiter);
    string query = pch;

    // Check if the command belongs to the "one" array
    int length = sizeof(one)/sizeof(one[0]);
    for(int i=0;i<length;i++){
        if(one[i] == query)
            return 1;
    }

    // Check if the command belongs to the "two" array
    length = sizeof(two)/sizeof(two[0]);
    for(int i=0;i<length;i++){
        if(two[i] == query)
            return 2;
    }

    // Check if the command belongs to the "three" array
    length = sizeof(three)/sizeof(three[0]);
    for(int i=0;i<length;i++){
        if(three[i] == query)
            return 3;
    }

    // If the command does not match any of the arrays, return 0
    return 0;
}