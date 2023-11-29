#include "global.h"
#include "tools.h"

void SUI(string arg, string registers[],bool flag[])
{
    /*Performs immediate subtraction and stores in accumulator*/
    registers[0] = hexSub(arg,registers[0],flag,true);	
}