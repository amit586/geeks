int s=0,ri,ro=0,max=0,j=0;
    for(int i=0;i<N;i++)
    {
        s+=arr[i];
        ro+=arr[i]*i;
    }
    max = ro;
    ri = ro;
    while(j!=N-1)
    {
        ri = (ri+s)-(N)*arr[N-1-j];
        if(ri>max)
            max = ri;
        j++;
    }
    return max;