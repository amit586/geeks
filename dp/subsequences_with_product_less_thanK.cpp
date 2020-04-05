#include <bits/stdc++.h>
#define MAX 100
using namespace std;

int dp[MAX][MAX];

int kproduct(vector <int> &v,int n,int k,int i,long long prod)
{
	//cout<<"call"<<endl;
	if(i==n)
		return 0;
	else if(dp[i][prod]!=0)
		return dp[i][prod];
	else
	{
		if(prod*v[i]<=k)
			dp[i][prod]= 1 + kproduct(v,n,k,i+1,prod) + kproduct(v,n,k,i+1,v[i]*prod) ;
		else
			dp[i][prod]= kproduct(v,n,k,i+1,prod);
		return dp[i][prod];
	}

	// long long dp[k+1][n+1];
	// memset(dp,0,sizeof(dp));
	// for(int i=1;i<=k;i++)
	// {
	// 	for(int j=1;j<)
	// }
	
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,k;
		cin>>n>>k;
		memset(dp,0,sizeof(dp));
		std::vector<int> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		cout<<kproduct(v,n,k,0,1)<<endl;
	}
	return 0;
}