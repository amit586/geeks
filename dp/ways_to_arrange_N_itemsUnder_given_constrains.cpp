#include <bits/stdc++.h>
#define ll long long
#define P 1000000007
using namespace std;

int arrangement(vector<int> &ki,int k,int n)
{
	vector<vector<ll>> C(n+1,vector<ll>(n+1,1));
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(i==j || j==0)
				C[i][j]=1;
			else
				C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;
		}
	}

	//cout<<C[3][2]<<endl;

	vector<ll> dp(k+1,0);
	int count=0;
	dp[0]=1;
	for(int i=0;i<k;i++)
	{
		count+=ki[i];
		dp[i+1]=(dp[i]*C[count-1][ki[i]-1])%P;
	}
	return dp[k];
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,k;
		cin>>n>>k;
		vector<int> ki(k);
		for(int i=0;i<k;i++)
			cin>>ki[i];

		cout<<arrangement(ki,k,n)<<endl;

	}
	return 0;
}