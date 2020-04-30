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
		vector<int> dp(n+1);
		dp[0]=1;
		dp[1]=1;
		dp[2]=1;
		dp[3]=2;
		dp[4]=dp[3]+dp[1]+1;
		for (int i = 5; i <= n; ++i)
			dp[i] = dp[i-1]+dp[i-3]+dp[i-4];
		cout<<dp[n]<<endl;
		
	}
	return 0;
}
