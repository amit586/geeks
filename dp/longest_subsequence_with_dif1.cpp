#include<bits/stdc++.h>
#define MAX 1005
using namespace std;

//int dp[MAX][MAX];

//int ld1(vector <int> &v,int n,int i,int prev)
int ld1(vector <int> &v,int n)
{
	// if(i>=n)
	// 	return 0;
	// else
	// 	if(dp[i][prev]!=0)
	// 		return dp[i][prev];
	// else 
	// {
	// 	dp[i][prev] = ld1(v,n,i+1,prev);
	// 	if(abs(v[prev]-v[i])==1)
	// 		dp[i][prev]= max(dp[i][prev],1+ld1(v,n,i+1,i));
	// 	return dp[i][prev];
	// }

	int dp[n+1];
	int ans=INT_MIN;
	for(int i=1;i<=n;i++)
	{
		int mx=0;
		for(int j=1;j<i;j++)
			if(abs(v[j-1]-v[i-1])==1)
				mx = max(mx,dp[j]);
		dp[i]=1+mx;
		ans = max(ans,dp[i]);
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
		vector <int> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		if(n==1)
		{
			cout<<1<<endl;
			continue;
		}
		cout<<ld1(v,n)<<endl;
		
		// int mx = INT_MIN;
		//memset(dp,0,sizeof(dp));
		// for(int i=1;i<n;i++)
		// 	mx = max(mx,ld1(v,n,i,i-1));
		//cout<<mx+1<<endl;
	}
	return 0;
}