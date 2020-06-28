#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define ll long long
#define ld long double
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first

using namespace std;

int LCS(string &s1)	
{
	// if(n1==0 || n2==0 )
	// 	return 0;
	// if(s1[n1-1]==s2[n2-1])
	// 	return 1+ LCS(n1-1,n2-1,s1,s2);
	// else
	// 	return max(LCS(n1,n2-1,s1,s2),LCS(n1-1,n2,s1,s2));
	int n = s1.size();
	vector<vector<int>> dp(n+1,vector<int> (n+1,0));
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(s1[i-1]==s1[n-j])
				dp[i][j] = 1+dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
		}
	}
	return dp[n][n];
}


int main()
{
	fio
	int TC;
	cin>>TC;
	//TC=1;
	while(TC--)
	{
		string s1,s2;
		cin>>s1;
		// s2 = s1;
		// reverse(all(s2));
		cout<<LCS(s1)<<endl;
	}
	return 0;
}
