#include <bits/stdc++.h>
using namespace std;

int subdiff(vector <int> &v,int n)
{
	vector<int> dp(n+1,1);

	int ans=INT_MIN;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
			if(abs(v[i-1]-v[j-1])<=1)
				dp[i]=max(dp[i],dp[j]+1);
		ans = max(dp[i],ans);
	}
	return ans;
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
		cout<<subdiff(v,n)<<endl;
	}
	return 0;
}