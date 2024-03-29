#include<fstream>
#include<iostream>
using namespace std;
#include"areas.cpp"
#include"input.cpp"
#include"tfunc.cpp"
#include"parallel.cpp"

int maxm(int x,int y)
{
    if(x>y)
        return x;
    return y;
}

int getMaxSum(int ***areas,int **matrix,int M,int N,int K)
{
    int sum=0;
    for(int i=0;i<=M-K;i++)
    {
        for(int j=0;j<=N-K;j++)
        {
            for(int x=0;x<=M-K;x++)
            {
                for(int y=0;y<=N-K;y++)
                {
                    int max=0;
                    if(intersect(i,j,i+K-1,j+K-1,x,y,K)==0)
                    {
                        //get the 3rd matrix as the maximum in all remaining areas
                        max=maxm(max,Tfun(areas,j,i,y,x,y-1,x-1,N,M,K));
                        max=maxm(max,Tfun(areas,j,i,y,x,y-1,x+K,N,M,K));
                        max=maxm(max,Tfun(areas,j,i,y,x,y+K,x-1,N,M,K));
                        max=maxm(max,Tfun(areas,j,i,y,x,y+K,x+K,N,M,K));
                        max=maxm(max,bottom(areas,N,M,y+K,i,j,K));
                        max=maxm(max,right(areas,N,M,x+K,i,j,K));
                        int tmp=(matrix[i][j]+matrix[x][y]+max);
                        if(tmp>sum)
                        {
                            sum=tmp;
                        }
                    }
                }
            }
        }
    }
    return sum;
}

int main(int argc, char *argv[])
{
    //read test file
    int M,N;    //M is no. of columns and N is no. of rows
    ifstream input;

    if(argc != 3)//To make sure that K is inputed.
    {
        cout<<"Input format is: './main <testFile> <K>'\n";
        return 0;
    }

    input.open(argv[1], ios::in);
    input>>M;
    input>>N;
    input.close();

    int K= atoi(argv[2]);//
    //int K=2;
    if(K<=0)
    {
        cout<<"incorrect value of K..."<<endl;
        return 0;
    }

    if(!(((K<=M && M<(2*K)) && N>=(3*K)) || (((2*K)<=M && M<(3*K)) && N>=(2*K)) || (((3*K)<=M) && N>=K)))//Make sure that K is less than M and N
    {
        cout<<"K is too large..."<<endl;
        return 0;
    }

    int **inputArray = inputFunction(argv[1]);
    int **sumArray= getSumArray(inputArray, M, N, K);
    int ***areas=new int**[M+1];
    for(int i=0;i<=M;i++)
    {
        areas[i]=new int*[N+1];
        for(int j=0;j<=N;j++)
            areas[i][j]=new int[4];
    }
   getMaxInArea(areas,sumArray,M,N,K);
   cout<<"Maximum output is:"<<getMaxSum(areas,sumArray,M,N,K)<<endl;
}
