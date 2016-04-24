#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main()
	{
	srand(time(NULL));
	int i=1,a,n,m;
	fstream f;
	f.open("test3.dat",ios::in | ios::trunc | ios::out);
	n=(rand()%40)+2;
	m=(rand()%40)+2;
	cout<<"M(number of Coloumns): "<<n<<"   N(Number of rows): "<<m<<endl;
	f<<n<<" "<<m;
	f<<"\n";
	while(i<=(m*n))
	{
		a=rand()%10;
		//cout<<a<<" ";
		if(a!=0)
		{
			//cout<<a<<" ";
			f<<a<<" ";
			if((i%n)==0)
			{
				//cout<<"\n";
				f<<"\n";
			}
			i++;
		}
	}
	return 0;
	}
