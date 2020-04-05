#include <bits/stdc++.h>
using namespace std;

int max(int a,int b,int c)
{
	return max(a,max(b,c));
}

int LCS3(const string &s1,const	string &s2,const string &s3,int l1,int l2,int l3)
{
	if(!(l1 && l2 && l3))
		return 0;
	// else
	// {
	// 	if(s1[i-1]== s2[j-1] && s2[j-1]==s3[k-1])
	// 		return 1 + LCS3(s1,s2,s3,i-1,j-1,k-1);
	// 	else
	// 		return max(LCS3(s1,s2,s3,i-1,j,k),LCS3(s1,s2,s3,i,j-1,k),LCS3(s1,s2,s3,i,j,k-1));
	// }

	int dp[2][l2+1][l3+1];
	memset(dp,0,sizeof(dp));

	for(int i=1;i<=l1;i++)
	{
		for(int j=1;j<=l2;j++)
		{
			for(int k=1;k<=l3;k++)
			{
				if(s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1])
					dp[i%2][j][k]=1+dp[(i-1)%2][j-1][k-1];
				else
					dp[i%2][j][k] = max(dp[(i-1)%2][j][k],dp[i%2][j-1][k],dp[i%2][j][k-1]);
			}
		}
	}
	return dp[l1%2][l2][l3];
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		string s1,s2,s3;
		cin>>s1>>s2>>s3;
		cout<<LCS3(s1,s2,s3,s1.size(),s2.size(),s3.size())<<endl;
	}
	return 0;
}

// AGGT12 
// 12TXAYB
// 12XBA