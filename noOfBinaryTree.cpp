#include<bits/stdc++.h>
#define MAX 500
using namespace std;
long long dp[MAX];
long long catalan(int n)
{
	int ans=0;
	if(dp[n]!=0)
		return dp[n];
	for(int i=0;i<n;i++)
	{
		ans +=catalan(i)*catalan(n-i-1);
	}
	dp[n]=ans;
	return ans;
}

int main()
{
	int n;
	cin>>n;
	dp[0]=1;
	dp[1]=1;
	dp[2]=2;
	dp[3]=5;
	cout<<catalan(n)<<endl;
	return 0;
}
