#include <bits/stdc++.h>
using namespace std;

int dp[10000];

bool check(string &s)
{
	if(s[0]=='0')
		return false;

	for(int i=1;i<s.size();i++)
	{
		if(s[i]=='0' && (s[i-1]=='0' or s[i-1]>'2'))
			return false;
	}
	return true;
}


int solve(string &s,int i)
{
	// if(i==s.size())
	//     return 1;
	//  int ans=0;
 //    if(s[i]!='0')
 //        ans+=solve(s,i+1);
 //    if(i+1<s.size() && (s[i]-'0')*10+(s[i+1]-'0')<=26)
 //        ans+=solve(s,i+2);
 //    return ans;

   	int n = s.size();
   	dp[n]=1;
   	for(int i=n-1;i>=0;i--)
   	{
   		dp[i]=0;
   		if(s[i]!='0')
   			dp[i]+=dp[i+1];
   		if(i+1<n and (s[i]-'0')*10 + (s[i+1]-'0')<=26 and (s[i]-'0')*10 + (s[i+1]-'0')>=10)
   			dp[i]+=dp[i+2];
	}
	// for(int i=0;i<=n;i++)
	// 	cout<<dp[i]<<" ";
	// cout<<endl;
   	return dp[0];
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		string s;
		cin>>n>>s;
		if(check(s))
			cout<<solve(s,0)<<endl;
		else
			cout<<0<<endl;
	}
	return 0;
}