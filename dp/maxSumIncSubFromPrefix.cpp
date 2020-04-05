#include <bits/stdc++.h>
using namespace std;

// int maxSubi(vector <int> &v,int n,int k,int pre)
// {
// 	v[pre+1]=v[k];
// 	vector<int> dp(pre+3,0);

// 	for(int i=1;i<pre+3;i++)
// 		dp[i]=v[i-1];
// 	for(int i=1;i<=pre+2;i++)
// 		for(int j=1;j<i;j++)
// 			if(v[j-1]<v[i-1])
// 				dp[i]=max(dp[i],v[i-1]+dp[j]);

// 	// cout<<endl;
// 	// for(int i=0;i<=pre+2;i++)
// 	// 	cout<<dp[i]<<endl;
// 	return dp[pre+2];
// }

int maxSubi(vector <int> &v,int n,int k,int pre)
{
	int dp[n][k];

	for(int i=0;i<n;i++)
		if(v[0]<v[i])
			dp[0][i]=v[i]+v[0];

	
}


int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,k,prev;
		cin>>n>>k>>prev;
		vector <int> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];

		cout<<maxSubi(v,n,k,prev)<<endl;
	}
	return 0;
}