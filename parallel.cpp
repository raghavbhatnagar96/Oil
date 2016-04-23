int bottom(int ***areas,int N,int M,int n,int matx,int maty,int K)
{
    if(n<N)
    {
        if(intersect(0,n,M-1,N-1,matx,maty,K)==0)
        {
            //cout<<M<<" "<<(N-n)<<" "<<areas[M][N-n][2]<<endl;
            return areas[M][N-n][2];
        }
    }
    
    return 0;
}

int right(int ***areas,int N,int M,int m,int matx,int maty,int K)
{
    if(m<M)
    {
        if(intersect(m,0,M-1,N-1,matx,maty,K)==0)
        {
            //cout<<(M-m)<<" "<<N<<" "<<areas[M-m][N][1]<<endl;
            return areas[M-m][N][1];
        }
    }
    
    return 0;
}
