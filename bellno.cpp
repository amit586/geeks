#include <bits/stdc++.h>
#define MAX 1000
using namespace std;
unsigned long long dp[500][500];

unsigned long long bell(int n)
{
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j==0)
				dp[i][j]=dp[i-1][j-1];
			else
				dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
		}

	}
	return dp[n-1][n-1];
}


int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	dp[0][0]=1;
	cout<<bell(n)<<endl;
	return 0;
}