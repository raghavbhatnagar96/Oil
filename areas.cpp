
/*
int sum(int **matrix,int x,int y,int k)
{
    int s=0;
    for(int i=x;i<(i+k);i++)
    {
        for(int j=y;j<(y+k);j++)
            s+=matrix[x][y];
    }
}
*/

int matrixMax(int **matrix,int startx,int starty,int endx,int endy,int k)
{
    int max=0;
    for(int x=startx;x<=(endx-k+1);x++)    
    {
        for(int y=starty;y<=(endy-k+1);y++)    
        {
            if(matrix[x][y]>max)
                max=matrix[x][y];
        }
    }
    cout<<"max is: "<<startx<<" "<<starty<<" "<<endx<<" "<<endy<<" "<<max<<endl;
    return max;
}

void fourCorners(int ***areas,int **matrix,int m,int n,int k,int i,int j)
{
    areas[i][j][0]=matrixMax(matrix,0,0,i-1,j-1,k);
    areas[i][j][1]=matrixMax(matrix,m-i,0,m-1,j-1,k);
    areas[i][j][2]=matrixMax(matrix,m-i,n-j,m-1,n-1,k);
    areas[i][j][3]=matrixMax(matrix,0,n-j,i-1,n-1,k);
}

/*
void recur(int ****areas,int **matrix,int m,int n,int k,int startx,int starty,int endx,int endy)
{
    if(endx<0 || endy<0 || startx==(m-k) || starty==(n-k))
        return;
    if(startx==endx && starty==endy)
        return;
    areas[startx][starty][endx][endy]=max(matrix,startx,starty,endx,endy,k);
    recur(areas,matrix,m,n,k,startx+1,starty,endx,endy);
    recur(areas,matrix,m,n,k,startx,starty+1,endx,endy);
    recur(areas,matrix,m,n,k,startx,starty,endx-1,endy);
    recur(areas,matrix,m,n,k,startx,starty,endx,endy-1);
    cout<<startx<<" "<<starty<<" "<<endx<<" "<<endy<<endl;
}
*/

void getMaxInArea(int ***areas,int **matrix,int m,int n,int k)
{
    for(int i=k;i<=m;i++)
    {
        for(int j=k;j<=n;j++)
            fourCorners(areas,matrix,m,n,k,i,j);
    }
}
