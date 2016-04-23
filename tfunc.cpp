#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

//M - columns
//N - rows
//dimensions written as NxM
int Tfun(int fx, int fy, int sx, int sy, int mx, int my, int N, int M)
	{
	int max=0,a,b,c,d,e,f,g,h,i,j,k,l;
	if((!intersect(0,0,N-1,my,fx,fy)) && (!intersect(0,0,N-1,my,sx,sy)))
		{
		a=MAXTOPLEFT; // (N-1) x (mx)
		if(max>a)
			max=a;
		}
	if((!intersect(0,my,mx,M-1,fx,fy)) && (!intersect(0,my,mx,M-1,sx,sy)))
		{
		b=MAXTOPRIGHT; //(mx) x (M-1-my)
		if(max>b)
			max=b;
		}
	if((!intersect(mx,my,N-1,M-1,fx,fy)) && (!intersect(mx,my,N-1,M-1,sx,sy)))
		{
		c=MAXBOTRIGHT; //(N-1-mx) x (M-1-my)
		if(max>c)
			max=c;
		}
	
	if((!intersect(0,0,mx,my,fx,fy)) && (!intersect(0,0,mx,my,sx,sy)))
		{
		d=MAXTOPLEFT; //(mx) x (my)
		if(max>d)
			max=d;
		}
	if((!intersect(mx,0,N-1,my,fx,fy)) && (!intersect(mx,0,N-1,my,sx,sy)))
		{
		e=MAXBOTLEFT; //(N-1-mx) x (my)
		if(max>e)
			max=e;
		}
	if((!intersect(0,my,N-1,M-1,fx,fy)) && (!intersect(0,my,N-1,M-1,sx,sy)))
		{
		f=MAXTOPRIGHT;// (N-1) x (M-1-my)
		if(max>f)
			max=f;
		}

	if((!intersect(0,0,mx,my,fx,fy)) && (!intersect(0,0,mx,my,sx,sy)))
		{
		g=MAXTOPLEFT; //(mx) x (my)
		if(max>g)
			max=g;
		}
	if((!intersect(0,my,mx,M-1,fx,fy)) && (!intersect(0,my,mx,M-1,sx,sy)))
		{
		h=MAXTOPRIGHT; //(mx) x (M-1-my)
		if(max>h)
			max=h;
		}
	if((!intersect(mx,0,N-1,M-1,fx,fy)) && (!intersect(mx,0,N-1,M-1,sx,sy)))
		{
		i=MAXBOTRIGHT;//(N-1-mx) x (M-1)
		if(max>i)
			max=i;
		}
	
	if((!intersect(0,0,mx,M-1,fx,fy)) && (!intersect(0,0,mx,M-1,sx,sy)))
		{
		j=MAXTOPRIGHT; // (mx) x (M-1)
		if(max>j)
			max=j;
		}
	if((!intersect(mx,0,N-1,my,fx,fy)) && (!intersect(mx,0,N-1,my,sx,sy)))
		{
		k=MAXBOTLEFT; //(N-1-mx) x (my)
		if(max>k)
			max=k;
		}
	if((!intersect(mx,my,N-1,M-1,fx,fy)) && (!intersect(mx,my,N-1,M-1,sx,sy)))
		{
		l=MAXBOTRIGHT;//(N-1-mx) x (M-1-my)
		if(max>l)
			max=l;
		}
	
	return max;
	}
	
int main()
	{
	return 0;
	}
