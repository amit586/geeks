#include <bits/stdc++.h>
using namespace std;

int dp[1010][1010];

int solve(int W,int N,int v[],int w[])
{
    if(W==0 or N==0)
        return 0;
    if(dp[N][W]!=-1)
    	return dp[N][W];
    if(W - w[N-1]<0)
        dp[N][W]=solve(W,N-1,v,w);
    else
    	dp[N][W]= max(v[N-1]+solve(W-w[N-1],N-1,v,w),solve(W,N-1,v,w));
    return dp[N][W];
}

int main() {
	int tc;
	cin>>tc;
	while(tc--)
	{
	    int n,mw;
	    cin>>n>>mw;
	    int v[n],w[n];
	    for(int i=0;i<n;i++)    cin>>v[i];
	    for(int i=0;i<n;i++)    cin>>w[i];
	    memset(dp,-1,sizeof(dp));
	    cout<<solve(mw,n,v,w)<<endl;
	}
	return 0;
}