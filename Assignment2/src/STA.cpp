#include "global.h"
#include "tools.h"

void STA (string arg1,string registers[],bool flag[],map<string,string> &memory)
{
    memory[arg1]=registers[0];
}