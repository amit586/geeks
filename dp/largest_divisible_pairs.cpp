#include <bits/stdc++.h>
using namespace std;

int computeMax(vector <int> &v,int n,int l,int dp[])
{
	if(n==0)
		return 0;
	if(dp[n]==-1)
	{
		if(v[l]%v[n-1]==0)
		{
			dp[n]=1+computeMax(v,n-1,l-1,dp);
		}
		else
		{
			dp[n]=computeMax(v,n-1,l,dp);
		}
	}
	return dp[n];

}


int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		int temp;
		std::vector<int> v;
		for (int i = 0; i < n; ++i)
		{
			cin>>temp;
			v.push_back(temp);
		}

		int dp[n+1];
		for (int i = 0; i < n+1; ++i)
		{
			dp[i]=-1;
		}
		sort(v.begin(),v.end());
		int m=INT_MIN;
		for(int i=n-1;i!=0;i--)
		{
			m = max(computeMax(v,i,i,dp),m);
		}
		cout<<m<<endl;
	}
	return 0;
}