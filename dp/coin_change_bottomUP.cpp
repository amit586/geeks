#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define f(i,j,k)  for(int i=j;i<k;i++)
#define fr(i,j,k) for(int i<=k-1;i>=j;i--)
#define ll long long
#define ld long double

using namespace std;

int coinChange(vector<int> &v,int n,int sum)
{
	// if(sum==0)
	// 	return 1;
	// if(sum<0)
	// 	return 0;
	// else if(n<=0 && sum>=0)
	// 	return 0;
	// else
	// {
	// 	return coinChange(v,n-1,sum)+coinChange(v,n,sum-v[n-1]);
	// }

	vector<vector<int>> dp(sum+1,vector<int>(n+1,0));
	for(int i=0;i<=n;i++)
		dp[i][0]=0;
	for(int i=0;i<=n;i++)
		dp[0][i]=1;

	for(int i=1;i<=sum;i++)
	{
		for(int j=1;j<=n;j++)
			dp[i][j] = dp[i][j-1]+(i-v[j-1]>=0?dp[i-v[j-1]][j]:0);
	}
	return dp[sum][n];


}

int main()
{
	fio
	int TC;
	cin>>TC;
	//TC=1;
	while(TC--)
	{
		int k,n;
		cin>>n>>k;
		std::vector<int> v(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
		}
		cout<<coinChange(v,n,k)<<endl;
		
	}
	return 0;
}
