#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int **inputFunction(const char* filename)//Returns the inputArray
{
    int M,N,i,j; //M rows and N coloumns!!M is coloumns if M N is inputed
    fstream input;
    input.open(filename, ios::in);
    input>>M;
    input>>N;
    int** inputArray = new int*[M];
    for(i=0;i<M;i++)
    {
        inputArray[i]=new int[N];
    }
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            input>>inputArray[i][j];
        }
    }
    return inputArray;
}

int **getSumArray(int **inputArray, int M, int N, int K)//returns 2D array of size MXN with each number being sum of the i,j to i+k,j+k the submatrix
{
    int i,j,x,y,sum;
    int **sumArray;
    sumArray=(int**)calloc(M, sizeof(int*));
    for(i=0;i<M;i++)
    {
        sumArray[i]=(int*)calloc(N, sizeof(int));
    }

    for(i=0;i<M-K+1;i++)
    {
        for(j=0;j<N-K+1;j++)
        {
            sum=0;
            for(x=i;x<i+K;x++)
            {
                for(y=j;y<j+K;y++)
                {
                    sum=sum+inputArray[x][y];
                }
            }
            sumArray[i][j]=sum;
        }
    }
    return sumArray;
}

/*
int main(int argc, char *argv[])
{
    int M,N;
    fstream input;
    input.open("test.dat", ios::in);
    input>>M;
    input>>N;
    if(argc != 2)//To make sure that K is inputed.
    {
        cout<<"Input format is: './oil <K>'\n";
        return 0;
    }
    int K= atoi(argv[1]);//
    if((K>M)||(K>N))//Make sure that K is less than M and N
    {
        return 0;
    }
    int **inputArray = inputFunction("test.dat");
    int **sumArray= getSumArray(inputArray, M, N, K);
    
    //////
    for(int i=0;i<M;i++)//Test case for making sure that getSumArray and inputFunction work
    {
        for(int j=0;j<N;j++)
        {
            cout<<inputArray[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<sumArray[i][j]<<" ";
        }
        cout<<"\n";
    }
    ///////
}
*/
