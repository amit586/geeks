#include <bits/stdc++.h>
using namespace std;
int dp[300][300];

int count(vector<int> & arr,int m , int n)
{
	if(n==0)
	{
		dp[n][m]=1;
	}
	if(n<0)
		return 0;
	if(n>=1 && m <=0)
		return 0;
	if(dp[n][m]!=0)
		return dp[n][m];
	else
		dp[n][m]= count(arr,m-1,n)+ count(arr,m,n-arr[m-1]);
		return dp[n][m];
}


int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		memset(dp,0,sizeof(dp));
		int m;
		cin>>m;
		vector <int> coins;
		int x;
		for (int i = 0; i < m; ++i)
		{
			cin>>x;
			coins.push_back(x);
		}
		int n;
		cin>>n;
		sort(coins.begin(),coins.end());
		cout<<count(coins,m,n)<<endl;
	}
	return 0;
}