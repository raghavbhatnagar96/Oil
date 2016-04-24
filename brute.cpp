#include<fstream>
#include<iostream>
using namespace std;
#include"input.cpp"
#include"intersection.cpp"

int maxm(int x,int y)
{
    if(x>y)
        return x;
    return y;
}

int getMaxSum(int **matrix,int M,int N,int K)
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
                    for(int w=0;w<=M-K;w++)
                    {
                        for(int z=0;z<=N-K;z++)
                        {
                            int max=0;
                            if(intersect(i,j,i+K-1,j+K-1,x,y,K)==0 && intersect(i,j,i+K-1,j+K-1,w,z,K)==0 && intersect(w,z,w+K-1,z+K-1,x,y,K)==0)
                            {
                                int tmp=(matrix[i][j]+matrix[x][y]+matrix[w][z]);
                                if(tmp>sum)
                                {
                                    sum=tmp;
                                    //cout<<"max is:"<<i<<" "<<j<<" "<<x<<" "<<y<<" "<<max<<" "<<sum<<endl;
                                }
                            }
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
        cout<<"Input format is: './oil <testFile> <K>'\n";
        return 0;
    }

    input.open(argv[1], ios::in);
    input>>M;
    input>>N;
    input.close();

    int K= atoi(argv[2]);//
    //int K=2;
    if((K>M)||(K>N))//Make sure that K is less than M and N
    {
        return 0;
    }

    int **inputArray = inputFunction(argv[1]);
    int **sumArray= getSumArray(inputArray, M, N, K);
    cout<<"Maximum output is:"<<getMaxSum(sumArray,M,N,K)<<endl;
    //cout<<Tfun(areas,0,4,4,4,8,3,N,M,K)<<endl;
}
