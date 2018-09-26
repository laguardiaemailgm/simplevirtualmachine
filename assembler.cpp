#include <windows.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
// INSTRUCTION SET (or Assembler Language)
// instruction = machine code [operand]
const int CLR    = 2147483600;  // acc= 0
const int ADD    = 2147483599;  // ADD 6,  acc = acc +6
const int MUL    = 2147483598; // mul 7,  acc = acc x 7
const int BNZ    = 2147483597; // BNZ 10, if (acc!=0) step=10
const int OUTPUT = 2147483596; // output,  cout << acc;
const int HALT   = 2147483595; // Halt,  exit program
const int SUB    = 2147483594;  // sub 4, acc = acc-4
const int NOP    = 2147483593;   // do nothing.
const int LOAD   = 2147483592;
const int AD     = 2147483591;
// VIRTUAL COMPUTER
int main()
{
// Simulating a single Register (accumulator) system
int opcode, operand; // IR register
int step = 0;        // PC register
int acc = 0;         // single accumulator
SetConsoleTitleA(" A Simple Virtual Machine");

//------------------------------------------------

int TABLEMAXSIZE=2048;
int table[TABLEMAXSIZE];
ifstream myFileRead;
ofstream myFileWrite;
string filename = "";

cout<<"\nEnter File Name: ";
getline(cin,filename);

myFileRead.open(filename.c_str());

    if (myFileRead.fail())
    {
        cout<<"\nFile was not opened";
        cout<<"\nCheck File if it exist";

        exit(1);//close file
    }
    int i = 0;//Counter
    string buffer;

    while(myFileRead.good() && (i < TABLEMAXSIZE))
    {
        myFileRead >> buffer;
        if(buffer == "CLR")
        {
            table[i++] = CLR;
        }
        else if(buffer == "ADD")
        {
            table[i++] = ADD;
        }
        else if(buffer == "MUL")
        {
            table[i++] = MUL;
        }
        else if(buffer == "BNZ")
        {
            table[i++] = BNZ;
        }
        else if(buffer == "OUTPUT")
        {
            table[i++] = OUTPUT;
        }
        else if(buffer == "HALT")
        {
            table[i++] = HALT;
        }
        else if(buffer == "SUB")
        {
            table[i++] = SUB;
        }
        else if(buffer == "NOP")
        {
            table[i++] = NOP;
        }
        else if(buffer == "LOAD")
        {
            table[i++] = LOAD;
        }
        else if(buffer == "AD")
        {
            table[i++] = ADD;
        }
        else
        {
            table[i++] = atoi(buffer.c_str());
        }
    }
    filename += ".o";
    myFileWrite.open(filename.c_str());
    if (myFileWrite.fail())
    {
        cout<<"\nFile was not opened";
        cout<<"\nCheck File if it exist";

        exit(1);//close file
    }

    for(int j = 0 ; j < i ; j++)
    {
        myFileWrite<<table[j] << " "<<endl;
    }
cout<<"\""<<filename<<"\" "<<" Generated";
cout<<"\nUse the VirtualMachine to run program";
return 0;
}
