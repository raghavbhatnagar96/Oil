#include<stdlib.h>

int **inputFunction(const char* filename)//Returns the inputArray
{
    int M,N,i,j; //M is coloumns N is rows
    fstream input;
    input.open(filename, ios::in);
    input>>M;
    input>>N;
    int** inputArray = new int*[M];
    for(i=0;i<M;i++)
    {
        inputArray[i]=new int[N];
    }
    for(int j=0;j<N;j++)
    {
        for(int i=0;i<M;i++)
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
