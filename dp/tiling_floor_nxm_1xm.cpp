#include <bits/stdc++.h>
#define P 1000000007
using namespace std;

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,m;
		cin>>n>>m;
		if(n<m)
		{
		    cout<<1<<endl;
		    continue;
		}
		else if(n==m)
		{
		    cout<<2<<endl;
		    continue;
		}

		vector<long long> dp(n+1,0);
		dp[0]=0;
		for(int i=1;i<=n;i++)
		{
			if(i<m)
				dp[i]=1;
			else if(i>m)
				dp[i]=(dp[i-1]+dp[i-m])%P;
			else 
				dp[i]=2;
		}
		
		cout<<dp[n]<<endl;
	}
	return 0;
}