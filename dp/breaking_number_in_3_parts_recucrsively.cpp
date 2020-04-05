#include <bits/stdc++.h>
using namespace std;

int max(int a,int b,int c,int d)
{
	return max(a,max(b,max(c,d)));
}

int maxSum(int n)
{
	// if(n==0)
	// 	return 0;
	// if(n==1)
	// 	return 1;
	// else
	// 	return max(maxSum(n/2)+maxSum(n/3)+maxSum(n/4),n);

	int dp[n+1]={0};
	dp[0]=0;
	dp[1]=1;
	for(int i=2;i<=n;i++)
		dp[i] = max(dp[i/2]+dp[i/3]+dp[i/4],i);
	return dp[n];
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		cout<<maxSum(n)<<endl;
	}
	return 0;
}