// This file is part of an 8085 emulator project.
// It contains the implementation of the MVI (Move Immediate) instruction.

#include "header/global.h"
#include "header/tools.h"

void MVI (string arg1,string arg2,string registers[],bool flags[],map<string,string> &memory){
    if(arg1=="M"){
        // If arg1 is "M", move the immediate data (arg2) to the memory location specified by HL register pair
        string address=registers[5]+registers[6];
        memory[address]=arg2;
    }
    else{
        registers[registerNumber(arg1)]=arg2;
    }
}