#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		vector<int> dp(n+1,0);
		dp[1]=1;
		dp[0]=1;
		for(int i=2;i<=n;i++)
		{
			dp[i]=0;
			for(int j=0;j<i;j++)
				dp[i]+=dp[j]*dp[i-j-1];
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}