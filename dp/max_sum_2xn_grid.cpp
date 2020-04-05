#include <bits/stdc++.h>
using namespace std;

int maxSum(vector<vector<int>> &v,int n)
{
	vector<vector<int>> dp(2,vector<int> (5,0));
	dp[0][2] = v[0][2] + max(v[0][0],v[1][0]);
	dp[1][2] = v[1][2] + max(v[0][0],v[1][0]);
	dp[0][3] = v[0][3] + max(v[0][1],v[1][1]);
	dp[1][3] = v[1][3] + max(v[0][1],v[1][1]);
	//cout<<dp[0][0]<<" "<<dp[1][0]<<endl<<dp[0][1]<<" "<<dp[1][1]<<endl<<dp[0][2]<<" "<<dp[1][2]<<endl;

	for(int i=4;i<n;i++)
	{
		dp[0][i%5] = max(dp[0][(i-2)%5],dp[1][(i-2)%5])+v[0][i];
		dp[1][i%5] = max(dp[1][(i-2)%5],dp[0][(i-2)%5]) +v[1][i];
		//cout<<dp[0][i%5]<<" "<<dp[1][i%5]<<endl;
	}

	return max(dp[0][(n-1)%5],dp[1][(n-1)%5]);
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		vector<vector<int>> v(2,vector<int>(n));

		for(int i=0;i<2;i++)
			for(int j=0;j<n;j++)
				cin>>v[i][j];
		cout<<maxSum(v,n)<<endl;
	}
	return 0;
}