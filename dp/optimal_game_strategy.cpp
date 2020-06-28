#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<string.h>
#include<string>
#include<vector>
#include<math.h>
#include<set>
#include<queue>
#include<chrono>
#include<unordered_map>
#include<unordered_set>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define ll long long
#define ld long double
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second
using namespace std;

int dp[110][110][2];

int solve(int s,int e,int v[],bool p)
{
	if(s==e)
		return p?v[s]:0;
	if(s>e)
		return 0;
	if(dp[s][e][p]!=-1)
		return dp[s][e][p];
	if(p)
		dp[s][e][p]= max(v[s]+solve(s+1,e,v,!p),v[e]+solve(s,e-1,v,!p));
	else 
		dp[s][e][p]=min(solve(s+1,e,v,!p),solve(s,e-1,v,!p));
	//dp[s][e]= max(v[s]+max(solve(s+2,e,v),solve(s+1,e-1,v)),v[e]+max(solve(s+1,e-1,v),solve(s,e-2,v)));
	return dp[s][e][p];
}

int main()
{
	fio
	int TC;
	cin>>TC;
	//TC=1;
	while(TC--)
	{
		int n;
		cin>>n;
		int v[n];
		for (int i = 0; i < n; ++i)
			cin>>v[i];

		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				dp[i][j][0]=dp[i][j][1]=-1;
		cout<<solve(0,n-1,v,1)<<endl;
		
	}
	return 0;
}
