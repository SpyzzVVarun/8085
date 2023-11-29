#include "global.h"
#include "tools.h"

void ADI(string arg, string registers[],bool flag[])
{
    registers[0] = hexAdd(arg,registers[0],flag,true);
}