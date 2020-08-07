#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

int makePal(int start,int end,string &str)
{
	if(start>=end || start<0 || end>=str.size())
		return 0;

	if(dp[start][end]!=-1)
		return dp[start][end];

	if(str[start]==str[end])
		dp[start][end]= makePal(start+1,end-1,str);
	else 
		dp[start][end]= 1+min(makePal(start+1,end,str),makePal(start,end-1,str));

	return dp[start][end];
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		string s;
		cin>>s;
		// for(int i=0;i<100;i++)
		// 	for(int j=0;j<100;j++)
		// 		dp[i][j]=-1;
		// cout<<makePal(0,s.size()-1,s)<<endl;			
		memset(dp,0,sizeof(dp));
		int n = s.size();
		for(int gap = 1;gap<n;gap++)
			for(int l = 0,h = gap;h<n;l++,h++)
				dp[l][h] = s[l]==s[h]?dp[l+1][h-1]:1+min(dp[l+1][h],dp[l][h-1]);
		cout<<dp[0][n-1]<<endl;
	}
	return 0;
}