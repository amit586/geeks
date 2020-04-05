#include <bits/stdc++.h>
#define MAX 55
using namespace std;

int min(int a,int b,int c)
{
	return min(a,min(b,c));
}

int maxSquare(vector <vector<int>> &v,int n,int m,int one)
{
	vector <vector<int>> dp(n,vector<int> (m));
	int mx = one;
	for(int i=0;i<n;i++)
		dp[i][0]=v[i][0];
	for(int i=0;i<m;i++)
		dp[0][i]=v[0][i];
	
	for(int i=1;i<n;i++)
		for(int j=1;j<m;j++)
		{
			if(v[i][j]==1)
				dp[i][j] = min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+1;
			else 
				dp[i][j] = 0;
			mx = max(dp[i][j],mx);
		}
	return mx;
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,m;
		cin>>n>>m;
		int one=0;
		vector <vector <int>> v(n,vector<int> (m,0));
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				cin>>v[i][j];
				if(v[i][j]==1)
					one=1;
			}

		cout<<maxSquare(v,n,m,one)<<endl;
	}
	return 0;
}