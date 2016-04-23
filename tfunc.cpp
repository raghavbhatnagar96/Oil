#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;
#include"intersection.cpp"

//M - columns
//N - rows
//dimensions written as NxM
int Tfun(int ***areas,int fx, int fy, int sx, int sy, int mx, int my, int N, int M,int K)
	{
	int max=0,a,b,c,d,e,f,g,h,i,j,k,l;
	if((!intersect(0,0,N-1,my,fx,fy,K)) && (!intersect(0,0,N-1,my,sx,sy,K)))
		{
		a=areas[mx+1][N][1];//MAXTOPLEFT; // (N-1) x (mx)
		if(max>a)
			max=a;
		}
	if((!intersect(0,my,mx,M-1,fx,fy,K)) && (!intersect(0,my,mx,M-1,sx,sy,K)))
		{
		b=areas[M-my][mx+1][1];//MAXTOPRIGHT; //(mx) x (M-1-my)
		if(max>b)
			max=b;
		}
	if((!intersect(mx,my,N-1,M-1,fx,fy,K)) && (!intersect(mx,my,N-1,M-1,sx,sy,K)))
		{
		c=areas[M-my][N-mx][2];//MAXBOTRIGHT; //(N-1-mx) x (M-1-my)
		if(max>c)
			max=c;
		}
	
	if((!intersect(0,0,mx,my,fx,fy,K)) && (!intersect(0,0,mx,my,sx,sy,K)))
		{
		d=areas[my+1][mx+1][1];//MAXTOPLEFT; //(mx) x (my)
		if(max>d)
			max=d;
		}
	if((!intersect(mx,0,N-1,my,fx,fy,K)) && (!intersect(mx,0,N-1,my,sx,sy,K)))
		{
		e=areas[my+1][N-mx][2];//MAXBOTLEFT; //(N-1-mx) x (my)
		if(max>e)
			max=e;
		}
	if((!intersect(0,my,N-1,M-1,fx,fy,K)) && (!intersect(0,my,N-1,M-1,sx,sy,K)))
		{
		f=areas[M-my][N][1];//MAXTOPRIGHT;// (N-1) x (M-1-my)
		if(max>f)
			max=f;
		}

	if((!intersect(0,0,mx,my,fx,fy,K)) && (!intersect(0,0,mx,my,sx,sy,K)))
		{
		g=areas[my+1][mx+1][1];//MAXTOPLEFT; //(mx) x (my)
		if(max>g)
			max=g;
		}
	if((!intersect(0,my,mx,M-1,fx,fy,K)) && (!intersect(0,my,mx,M-1,sx,sy,K)))
		{
		h=areas[M-my][mx+1][1];//MAXTOPRIGHT; //(mx) x (M-1-my)
		if(max>h)
			max=h;
		}
	if((!intersect(mx,0,N-1,M-1,fx,fy,K)) && (!intersect(mx,0,N-1,M-1,sx,sy,K)))
		{
		i=areas[M][N-mx][2];//MAXBOTRIGHT;//(N-1-mx) x (M-1)
		if(max>i)
			max=i;
		}
	
	if((!intersect(0,0,mx,M-1,fx,fy,K)) && (!intersect(0,0,mx,M-1,sx,sy,K)))
		{
		j=areas[M][mx+1][1];//MAXTOPRIGHT; // (mx) x (M-1)
		if(max>j)
			max=j;
		}
	if((!intersect(mx,0,N-1,my,fx,fy,K)) && (!intersect(mx,0,N-1,my,sx,sy,K)))
		{
		k=areas[my+1][N-mx][2];//MAXBOTLEFT; //(N-1-mx) x (my)
		if(max>k)
			max=k;
		}
	if((!intersect(mx,my,N-1,M-1,fx,fy,K)) && (!intersect(mx,my,N-1,M-1,sx,sy,K)))
		{
		l=areas[M-my][N-mx][2];//MAXBOTRIGHT;//(N-1-mx) x (M-1-my)
		if(max>l)
			max=l;
		}
	
	return max;
	}
	
/*
int main()
	{
	return 0;
	}
*/
