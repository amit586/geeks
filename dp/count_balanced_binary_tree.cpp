#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define f(i,j,k)  for(int i=j;i<k;i++)
#define fr(i,j,k) for(int i<=k-1;i>=j;i--)
#define ll long long
#define ld long double

using namespace std;

int main()
{
	fio
	int TC;
	cin>>TC;
	//TC=1;
	while(TC--)
	{
		int n;
		cin>>n;
		std::vector<ll> dp(n+1);
		dp[0]=1;
		dp[1]=1;
		dp[2]=3;
		dp[3]=15;
		for (int i = 3; i <= n; ++i)
			dp[i] = dp[i-1]*(dp[i-1]+2*dp[i-2]);
		cout<<dp[n]<<endl;
	}
	return 0;
}
