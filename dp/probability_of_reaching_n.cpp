#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t ;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		long double p;
		cin>>p;
		vector<long double> dp(max(N+1,4),0);
		dp[2]=p;
		dp[3]=1-p;
		for(int i=4;i<=N;i++)
			dp[i] = p*dp[i-2] + (1-p)*dp[i-3];
		cout<<dp[N]<<endl;
	}
	return 0;
}