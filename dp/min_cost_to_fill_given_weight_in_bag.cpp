#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define f(i,j,k)  for(int i=j;i<k;i++)
#define fr(i,j,k) for(int i<=k-1;i>=j;i--)
#define ll long long
#define ld long double
#define INF 1000000 
using namespace std;

int minCost(vector<int> &v,int n,int W)
{
	vector<int> val;
	vector<int> w;
	int size=0;
	for(int i=0;i<n;i++)
	{
		if(v[i]!=-1)
		{
			val.push_back(v[i]);
			w.push_back(i+1);
			size++;
		}
	}
	n = size;
	vector<vector<int>> dp(n+1,vector<int>(W+1));
	
	for(int i=0;i<=W;i++)
		dp[0][i] = INF;

	for(int i=1;i<=n;i++)
		dp[i][0] = 0;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=W;j++)
		{
			if(w[i-1]>j)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = min(dp[i-1][j],
					val[i-1]+dp[i][j-w[i-1]]);
		}
	}
	// cout<<endl;
	// for(int i=0;i<=n;i++)
	// {
	// 	for(int j=0;j<=W;j++)
	// 		cout<<dp[i][j]<<" ";
	// 	cout<<endl;
	// }
	return (dp[n][W]>=INF?-1:dp[n][W]);
	
}

int main()
{
	fio
	int TC;
	cin>>TC;
	//TC=1;
	while(TC--)
	{
		int n, k;
		cin>>n>>k;
		std::vector<int> v(n);
		for (int i = 0; i <n; ++i)
		{
			cin>>v[i];
		}
		cout<<minCost(v,n,k)<<endl;		
	}
	return 0;
}
