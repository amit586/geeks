#include <bits/stdc++.h>
using namespace std;

int LCS(const string &s1,const string &s2,int len1,int len2)
{
	// if(i<0 || j<0)
	// 	return 0;
	// else
	// {
	// 	if(s1[i]==s2[j])
	// 		return 1+ LCS(s1,s2,i-1,j-1);
	// 	else
	// 		return max(LCS(s1,s2,i-1,j),LCS(s1,s2,i,j-1));
	// }

	int dp[len1+1][len2+1];
	memset(dp,0,sizeof(dp));

	for(int i=1;i<=len1;i++)
	{
		for(int j=1;j<=len2;j++)
		{
			if(s1[i-1]==s2[j-1])
				dp[i][j]=1 +dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}

	// for(int i=0;i<len1;i++)
	// {
	// 	for(int j=0;j<len2;j++)
	// 		cout<<dp[i][j]<<" ";
	// 	cout<<endl;
	// }

	return dp[len1][len2];
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		string s1,s2;
		int a,b;
		cin>>a>>b;
		cin>>s1>>s2;
		cout<<LCS(s1,s2,s1.size(),s2.size())<<endl;
	}
	return 0;
}