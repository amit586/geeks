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
		int n,m;
		cin>>n>>m;
		vector<vector<int>> dp(n+1,vector<int> (m+1));
		for(int i=0;i<=n;i++)
			dp[i][0]=1;
		for(int i=0;i<=m;i++)
			dp[0][i]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				dp[i][j] = dp[i-1][j]+dp[i][j-1];
		cout<<dp[n][m]<<endl;

		
	}
	return 0;
}
