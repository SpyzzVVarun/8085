#include "header/global.h"
#include <fstream>
#include "header/tools.h"

class simulator8085
{
private:
     map<string,string> Memory;
     vector<string>sequence;
     string start;
     string pc;
     bool flag[8];
     string registers[7];
public :
	simulator8085(){
		
		for(int i = 0;i<7;i++)
			registers[i] = "NULL";
		
		for(int i=0;i<8;i++)
			flag[i] = false;
		
		start = "0000";
		pc = "0000";
        sequence.push_back(start);
	}
    void input()
    {
        cout<<"\nEnter the starting address:\n";
        cin>>start;
        pc = start;
        sequence.push_back(start);
    }
    void ProgramFile(char* filename)
    {
        ifstream input;
        input.open(filename);
        if(input.fail() == true){
			
			cout<<"You have entered an invalid filename\nThe prorgam will quit\n";
			exit(0);
		}
        string line;
        while(1)
        {
            getline(input,line);
            Memory[pc]=line;
            pc=updatedAddress(pc,Memory);
            if(line=="HLT"){
                break;
            }
            sequence.push_back(pc);
        }
        int size=sequence.size();
        for(int i=0;i<size;i++)
        {
            pc=execution(Memory[sequence[i]],registers,flag,Memory,pc);
        }
    }
};

int main(int argc,char* argv[])
{
    simulator8085 instance;
    // instance.input();
    // cout << argv[1] << "\n";
    instance.ProgramFile(argv[1]);
}