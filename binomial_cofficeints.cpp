#include<bits/stdc++.h>

using namespace std;

long long dp[999][801];

long long c(int n,int k)
{
	if(k==0 || k==n)
	{
		dp[n][k]=1;
		return 1;
	}	
	if(dp[n][k]!=0)
		return dp[n][k];
	else
	{
		dp[n][k]= c(n-1,k-1)+c(n-1,k);
		return dp[n][k];
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	
		int n,k;
		cin>>n>>k;
		cout<<c(n,k)<<endl;
	}
}
