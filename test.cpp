#include<fstream>
#include<iostream>
using namespace std;

int main()
{
    ofstream out;
    out.open("test4.dat");
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
            out<<"1 ";
        out<<endl;
    }
}

