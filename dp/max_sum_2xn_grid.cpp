#include <bits/stdc++.h>
using namespace std;

// int max(int a,int b,int c,int d)
// {
//     return max(a,max(b,max(c,d)));
// }

// int maxSum(vector<vector<int>> &v,int n)
// {
// 	vector<vector<int>> dp(2,vector<int> (n,0));
// 	dp[0][0]=v[0][0];
// 	dp[0][1]=v[0][1];
// 	dp[1][0]=v[1][0];
// 	dp[1][1]=v[1][1];
// 	dp[0][2]=v[0][2] + max(v[0][0],v[1][0]);
// 	dp[1][2]=v[1][2] + max(v[0][0],v[1][0]);
	
	
// 	for(int i=3;i<n;i++)
// 	{
// 	    dp[0][i] = v[0][i] + max(dp[0][i-2],dp[1][i-2],dp[0][i-3],dp[1][i-3]);
// 	    dp[1][i] = v[1][i] + max(dp[0][i-2],dp[1][i-2],dp[0][i-3],dp[1][i-3]);
// 	}
	
// // 	for(int i=0;i<n;i++)
// // 	    cout<<dp[0][i]<<" ";
// // 	cout<<endl;
// // 	for(int i=0;i<n;i++)
// // 	    cout<<dp[1][i]<<" ";
// // 	cout<<endl;
	
// 	int ans = max(dp[0][n-1],max(dp[1][n-1],max(dp[0][n-2],dp[1][n-2])));
	
// 	return ans;
// }

int maxSum(vector<vector<int>> &v,int n)
{
	int inc = max(v[1][0],v[0][0]);
	int exc = 0,exc_new;

	for(int i=1;i<n;i++)
	{
		exc_new = max(inc,exc);
		inc = max(v[0][i],v[1][i]) + exc;
		exc = exc_new;
	}
	return max(inc,exc);

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