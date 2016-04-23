
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

int max(int **matrix,int startx,int starty,int endx,int endy,int k)
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
    return max;
}

void getMaxInArea(int ****areas,int **matrix,int m,int n,int k)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int x=0;x<m;x++)
            {
                for(int y=0;y<n;y++)
                    areas[i][j][x][y]=max(matrix,i,j,x,y,k);
            }
        }
    }
}
