#include <bits/stdc++.h>
using namespace std;


int modSum(vector<int> v,int start,int end)
{
	int ans = 0;
	for(int i=start;i<=end;i++)
		ans= (ans+v[i])%100;
	return ans;
}

int minSumv(vector<int> &v,int n)
{
	vector<vector<int>> dp(n,vector<int> (n,0))	;

	for(int L=2;L<n;L++)
	{
		for(int i=1;i<n-L+1;i++)
		{
			int j = i+L-1;
			dp[i][j]=INT_MAX;
			
			for(int k=i;k<j;k++)
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j] + modSum(v,i,k)*modSum(v,k+1,j));
		}
	}
	return dp[1][n-1];
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		//cout<<1<<endl;

		cout<<minSumv(v,n)<<endl;
	}
	return 0;
}