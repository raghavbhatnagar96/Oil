#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<vector>

using namespace std;

/*int **inputFunction(const char* filename)//Returns the inputArray
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
*/

int intersection(int i,int j,int si,int sj,int K)
	{
	if((si<(i+K)) && (((sj>=j)&&(sj<(j+K))) || ((j>=sj)&&(j<(sj+K)))))
		return 1;
	return 0;
	}

int *getthirdmat(int i,int j,int si,int sj,int k)
	{
	int p=0;
	int *thirdmat=new int[2];
	int **sum=(int**)calloc(10, sizeof(int*));
	for(p=0;p<10;p++)
		sum[p]=(int*)calloc(3,sizeof(int));
	int cnum=0,mp=0,max=0;
	int mtempj=sj;
	int stempj=j;
	//int tempi=si;
	if(sj<j)
		{
		mtempj=j;
		stempj=sj;
		}
	sum[cnum++]=getmax(0,mtempj+K,M-K+1,N-K+1);
	sum[cnum++]=getmax(0,0,M-K+1,stempj-1);
	sum[cnum++]=getmax(0,stempj+K,M+K-1,mtempj-1);
	sum[cnum++]=getmax(0,0,i-1,N-K+1);
	sum[cnum++]=getmax(j+K,0,M+K-1,N+K-1);
	sum[cnum++]=getmax(i+K,0,si-1,N+K-1);
	max=sum[0][0];
	for(p=1;p<10;p++)
		{
		if(max<sum[p][0])
			{
			max=sum[p][0];
			mp=p;
			}
		}
	thirdmat[0]=sum[p][1];
	thirdmat[1]=sum[p][2];
	return thirdmat;
	}

int main()
	{
	//int **inputarray=inputFunction("test.dat", ios::in);
	int *thirdmat;
	int cnt=0,maxsum=0,pos=0,i,j,si,sj,p;
	int mul=M*N;
	int finsum=0,t1,t2;
	mul++;
	int **summat=(int**)calloc(mul, sizeof(int*));
	for(p=0;p<mul;p++)
		{
		summat[p]=(int*)calloc(7,sizeof(int));
		}
	for(i=0;i<M-K+1;i++)
		{
		for(j=0;j<N-K+1;j++)
			{
			//fx=i;
			//fy=j;
			for(si=i;si<M-K+1;si++)
				{
				for(sj=0;sj<N-K+1;sj++)
					{
					if(intersection(i,j,si,sj,k))
						continue;
					else
						{
						//sx=si;
						//sy=sj;
						}
					*thirdmat=getthirdmat(i,j,si,sj,k);
					t1=thirdmat[0];
					t2=thirdmat[1];
					finsum=sumArray[i][j]+sumArray[si][sj]+sumArray[t1][t2];
					summat[cnt][0]=finsum;
					summat[cnt][1]=i;
					summat[cnt][2]=j;
					summat[cnt][3]=si;
					summat[cnt][4]=sj;
					summat[cnt][5]=thirdmat[0];
					summat[cnt][6]=thirdmat[1];
					if (maxsum<finsum)
						{
						maxsum=finsum;
						pos=cnt;
						}
					cnt++;
					}
				}
			}
		}
	}
