#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll maxPIS(vector <int> v,int n)
{
	std::vector<ll> dp(n+1);
	// for (int i = 1; i <= n; ++i)
	// {
	// 	dp[i]=v[i-1];
	// }
	ll global_mx=INT_MIN;
	for(int i=1;i<=n;i++)
	{
		ll mx = 1;
		for(int j=1;j<i;j++)
			if(v[j-1]<v[i-1])
				mx = max(mx,dp[j]);
		dp[i]=mx*v[i-1];
		global_mx = max(global_mx,dp[i]);
	}
	
	return global_mx;
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

		cout<<maxPIS(v,n)<<endl;
	}
	return 0;
}