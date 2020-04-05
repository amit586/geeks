#include <bits/stdc++.h>
using namespace std;

int maxCost(vector<vector<int>> &v,int n)
{
	vector <vector<int >> dp(2,vector<int> (n,0));
	dp[0][0]=v[0][0];
	for(int i=1;i<n;i++)
	{
		dp[i%2][0] = v[i][0] + dp[(i-1)%2][0];
		for(int j=1;j<i;j++)
			dp[i%2][j] = max(dp[(i-1)%2][j-1],dp[(i-1)%2][j])+v[i][j];
		dp[i%2][i] = dp[(i-1)%2][i-1] + v[i][i];
	}
	int mx=dp[(n-1)%2][0];
	for(int i=1;i<n;i++)
		mx = max(dp[(n-1)%2][i],mx);
	return mx;
}

// int maxCost(vector<vector<int>> &v,int n)
// {
// 	vector <vector<int >> dp(n,vector<int> (n,0));
// 	dp[0][0]=v[0][0];
// 	for(int i=1;i<n;i++)
// 	{
// 		dp[i][0] = v[i][0] + dp[(i-1)][0];
// 		for(int j=1;j<i;j++)
// 			dp[i][j] = max(dp[(i-1)][j-2],dp[(i-1)][j])+v[i][j];
// 		dp[i][i] = dp[(i-1)][i-1] + v[i][i];
// 	}
// 	int mx=dp[(n-1)][0];
// 	for(int i=1;i<n;i++)
// 		mx = max(dp[(n-1)][i],mx);

// 	for(int i=0;i<n;i++)
// 	{
// 		for(int j=0;j<n;j++)
// 			cout<<dp[i][j]<<" ";
// 		cout<<endl;
// 	}

// 	return mx;
// }

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		vector <vector<int>> v(n,vector<int> (n));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>v[i][j];
		cout<<maxCost(v,n)<<endl;
	}
	return 0;
}