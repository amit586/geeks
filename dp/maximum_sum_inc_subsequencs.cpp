#include<bits/stdc++.h>
#define ll long long
using namespace std;

int maxSumIS(std::vector<int> v,int n)
{
	ll dp[n+1]={0};
	for(int i=1;i<=n;i++)
	{
		ll mx=0;
		for(int j=1;j<i;j++)
			if(v[j-1]<v[i-1])
				mx = max(mx,dp[j]);
		dp[i]=v[i-1]+mx;
	}
	ll mx=INT_MIN;
	for(int i=1;i<=n;i++)
		mx = max(mx,dp[i]);
	return mx;

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
		for (int i = 0; i < n; ++i)
		{
			/* code */cin>>v[i];
		}

		cout<<maxSumIS(v,n)<<endl;
	}
	return 0;
}