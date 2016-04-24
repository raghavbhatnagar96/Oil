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
	m=(rand()%100)+2;
	n=(rand()%100)+2;
	cout<<"M: "<<m<<"   N: "<<n<<endl;
	f<<m<<" "<<n;
	f<<"\n";
	while(i<=(m*n))
		{
		a=rand()%10;
		cout<<a<<" ";
		f<<a<<" ";
		if((i%n)==0)
			{
			cout<<"\n";
			f<<"\n";
			}
		i++;
		}
	return 0;
	}
