#include <bits/stdc++.h>
using namespace std;

int repeatingLCS(const string &s1,const string &s2,int len1,int len2)
{
	// if(i==0 ||j==0)
	// 	return 0;
	// else
	// {
	// 	if(s1[i-1]==s1[j-1] && i!=j)
	// 		return 1+repeatingLCS(s1,s2,i-1,j-1);
	// 	else
	// 		return max(repeatingLCS(s1,s2,i,j-1),repeatingLCS(s1,s2,i-1,j));
	// }

	int dp[2][len2+1];
	memset(dp,0,sizeof(dp));

	for(int i=1;i<=len1;i++)
	{
		for(int j=1;j<=len2;j++)
		{
			if(s1[i-1]==s1[j-1] && i!=j)
				dp[i%2][j]=1+dp[(i-1)%2][j-1];
			else
				dp[i%2][j]=max(dp[(i-1)%2][j],dp[i%2][j-1]);
		}
	}

	return dp[len1%2][len2];
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		cout<<repeatingLCS(s,s,s.size(),s.size())<<endl;
	}
	return 0;
}