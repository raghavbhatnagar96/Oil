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
    if(my>=M || mx>=N || my<0 || mx<0)
        return 0;
	int max=0,a,b,c,d,e,f,g,h,i,j,k,l;
    /*
	if((!intersect(0,0,my,N-1,fy,fx,K)) && (!intersect(0,0,my,N-1,sy,sx,K)))
		{
		a=areas[my+1][N][0];//MAXTOPLEFT; // (N-1) x (my)
        //cout<<"a:"<<a<<" ";
		if(max<a)
			max=a;
		}
    */
	if((!intersect(my,0,M-1,mx,fy,fx,K)) && (!intersect(my,0,M-1,mx,sy,sx,K)))
		{
		b=areas[M-my][mx+1][1];//MAXTOPRIGHT; //(mx) x (M-1-my)
        //cout<<"b:"<<b<<" ";
		if(max<b)
			max=b;
		}
	if((!intersect(my,mx,M-1,N-1,fy,fx,K)) && (!intersect(my,mx,M-1,N-1,sy,sx,K)))
		{
		c=areas[M-my][N-mx][2];//MAXBOTRIGHT; //(N-1-mx) x (M-1-my)
        //cout<<"c:"<<c<<" ";
		if(max<c)
			max=c;
		}
	
	if((!intersect(0,0,my,mx,fy,fx,K)) && (!intersect(0,0,my,mx,sy,sx,K)))
		{
		d=areas[my+1][mx+1][0];//MAXTOPLEFT; //(mx) x (my)
        //cout<<"d:"<<d<<" ";
		if(max<d)
			max=d;
		}
	if((!intersect(0,mx,my,N-1,fy,fx,K)) && (!intersect(0,mx,my,N-1,sy,sx,K)))
		{
		e=areas[my+1][N-mx][3];//MAXBOTLEFT; //(N-1-mx) x (my)
        //cout<<"e:"<<e<<" ";
		if(max<e)
			max=e;
		}
    /*
	if((!intersect(my,0,M-1,N-1,fy,fx,K)) && (!intersect(my,0,M-1,N-1,sy,sx,K)))
		{
		f=areas[M-my][N][1];//MAXTOPRIGHT;// (N-1) x (M-1-my)
        //cout<<"f:"<<f<<" ";
		if(max<f)
			max=f;
		}
    */

    /*
	if((!intersect(0,0,my,mx,fy,fx,K)) && (!intersect(0,0,my,mx,sy,sx,K)))
		{
		g=areas[my+1][mx+1][0];//MAXTOPLEFT; //(mx) x (my)
        //cout<<"g:"<<g<<" ";
		if(max<g)
			max=g;
		}

	if((!intersect(my,0,M-1,mx,fy,fx,K)) && (!intersect(my,0,M-1,mx,sy,sx,K)))
		{
		h=areas[M-my][mx+1][1];//MAXTOPRIGHT; //(mx) x (M-1-my)
        //cout<<"h:"<<h<<" ";
		if(max<h)
			max=h;
		}

	if((!intersect(0,mx,M-1,N-1,fy,fx,K)) && (!intersect(0,mx,M-1,N-1,sy,sx,K)))
		{
		i=areas[M][N-mx][2];//MAXBOTRIGHT;//(N-1-mx) x (M-1)
        //cout<<"i:"<<i<<" ";
		if(max<i)
			max=i;
		}
	
	if((!intersect(0,0,M-1,mx,fy,fx,K)) && (!intersect(0,0,M-1,mx,sy,sx,K)))
		{
		j=areas[M][mx+1][1];//MAXTOPRIGHT; // (mx) x (M-1)
        //cout<<"j:"<<j<<" ";
		if(max<j)
			max=j;
		}
    */
    /*
	if((!intersect(0,mx,my,N-1,fy,fx,K)) && (!intersect(0,mx,my,N-1,sy,sx,K)))
		{
		k=areas[my+1][N-mx][3];//MAXBOTLEFT; //(N-1-mx) x (my)
        //cout<<"k:"<<k<<" ";
		if(max<k)
			max=k;
		}
	if((!intersect(my,mx,M-1,N-1,fy,fx,K)) && (!intersect(my,mx,M-1,N-1,sy,sx,K)))
		{
		l=areas[M-my][N-mx][2];//MAXBOTRIGHT;//(N-1-mx) x (M-1-my)
        //cout<<"l:"<<l<<" ";
		if(max<l)
			max=l;
		}
    */
	
    //cout<<endl;
    //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" "<<g<<" "<<h<<" "<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
	return max;
	}
