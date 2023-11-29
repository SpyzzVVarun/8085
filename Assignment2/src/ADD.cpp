#include "header/global.h"
#include "header/tools.h"

void ADD(string arg1,string registers[],bool flag[],map<string,string>&memory){
    if(arg1 != "M"){
        /*Fetches index of register to access array string registers[]*/
        int registerID = registerNumber(arg1);
        /*Converting decimal value to string format and storing in accumulator*/
        registers[0] = hexAdd(registers[registerID],registers[0],flag,true);
        
    }
    else{                         
        /*Fetches data of HL pair*/
        string address = "";
        address = address + registers[5] + registers[6];
        /*Converting decimal value to string format and storing in accumulator*/
        registers[0] = hexAdd(memory[address],registers[0],flag,true);				 			
    }
}