#include<iostream>
using namespace std;
#include"areas.cpp"
#include"input.cpp"

int main(int argc, char *argv[])
{
    int M,N;
    fstream input;
    input.open("test.dat", ios::in);
    input>>M;
    input>>N;

    /*
    if(argc != 2)//To make sure that K is inputed.
    {
        cout<<"Input format is: './oil <K>'\n";
        return 0;
    }
    */

    //int K= atoi(argv[1]);//
    int K=2;
    if((K>M)||(K>N))//Make sure that K is less than M and N
    {
        return 0;
    }

    int **inputArray = inputFunction("test.dat");
    int **sumArray= getSumArray(inputArray, M, N, K);
    int ***areas=new int**[M+1];
    for(int i=0;i<=M;i++)
    {
        areas[i]=new int*[N+1];
        for(int j=0;j<=N;j++)
            areas[i][j]=new int[4];
    }
   getMaxInArea(areas,sumArray,M,N,K); 
   cout<<areas[6][3][1]<<endl;
}
