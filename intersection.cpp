
int isInside(int w, int x, int y, int z, int a, int b)
{
    if(((a>=w)&&(a<=y))&&((b>=x)&&(b<=z)))
    {
        return 1;
    }
    return 0;
}


int intersect(int w, int x, int y, int z, int a, int b, int k)//(w,x) and (y,z) are the diagonal points of area. (a,b) is the upper right point of the sub-matrix
{
    int areaL=y-w+1;
    int areaB=z-x+1;

    if((areaL<k) || (areaB<k))
    {
        return 1;
    }
    else if(isInside(w, x, y, z, a, b))
    {
        return 1;
    }
    else if(isInside(w, x, y, z, a+k-1, b))
    {
        return 1;
    }
    else if(isInside(w, x, y, z, a, b+k-1))
    {
        return 1;
    }
    else if(isInside(w, x, y, z, a+k-1, b+k-1))
    {
        return 1;
    }
    else
        return 0;
}
