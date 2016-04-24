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
            int max=0;
            for(int x=0;x<=M-K;x++)
            {
                for(int y=0;y<=N-K;y++)
                {
                    if(intersect(i,j,i+K-1,j+K-1,x,y,K)==0)
                    {
                        //get the 3rd matrix as the maximum in all remaining areas
                        max=maxm(max,Tfun(areas,j,i,y,x,y,x,M,N,K));
                        max=maxm(max,Tfun(areas,j,i,y,x,y,x+K-1,M,N,K));
                        max=maxm(max,Tfun(areas,j,i,y,x,y+K-1,x,M,N,K));
                        max=maxm(max,Tfun(areas,j,i,y,x,y+K-1,x+K-1,M,N,K));
                        max=maxm(max,bottom(areas,M,N,y+K-1,i,j,K));
                        max=maxm(max,right(areas,M,N,x+K-1,i,j,K));
                        //cout<<"max is:"<<max<<endl;
                        //sum=maxm(sum,(matrix[i][j]+matrix[x][y]+max));
                        if((matrix[i][j]+matrix[x][y]+max)>sum)
                        {
                            sum=(matrix[i][j]+matrix[x][y]+max);
                            cout<<i<<" "<<j<<" "<<x<<" "<<y<<" "<<max<<" "<<sum<<endl;
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
    int M,N;    //M is no. of columns and Nis no. of rows
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
    //int K=2;
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
   cout<<"Maximum output is:"<<getMaxSum(areas,sumArray,M,N,K)<<endl;
}
