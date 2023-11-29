#include "global.h"
#include "tools.h"

void DCR(string arg,string registers[],bool flag[],map<string,string>&memory){
    if(arg != "M"){
        
        /*Performs INR on a register*/
        int registerID = registerNumber(arg);
        registers[registerID] = hexSub(registers[registerID],"01",flag,false);
    }
    else{
        /*Performs DCR on HL pair*/
        string address = "";
        address = address + registers[5] + registers[6];
        memory[address] = hexSub(memory[address],"01",flag,false);
    }
}