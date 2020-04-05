#include <bits/stdc++.h>
using namespace std;

int LCS(const vector <int> &v,int n)
{
	int dp[n+1]={0};
	dp[0]=1;

	for(int i=1;i<n;i++)
	{
		int mx = INT_MIN;

		for(int j=0;j<n;j++)
		{
			if(v[i]>v[j])
				mx = max(dp[j],mx);
		}
		if(mx==INT_MIN)
			dp[i]=1;
		else
			dp[i]=1+mx;
	}

	int mx=INT_MIN;
	for(int i=0;i<n;i++)
		mx = max(dp[i],mx);
	return mx;

	// int dp[n+1]={0};
	// for(int i=1;i<n;i++)
	// {
	// 	if(v[i]>=v[i-1])
	// 		dp[i]=1+dp[i-1];
	// 	else
	// 		dp[i]=dp[i-1];
	// }
	// return dp[n-1];
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		std::vector<int> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		cout<<LCS(v,n)<<endl;
	}
	return 0;
}