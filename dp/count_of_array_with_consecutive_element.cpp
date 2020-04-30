#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define f(i,j,k)  for(int i=j;i<k;i++)
#define fr(i,j,k) for(int i<=k-1;i>=j;i--)
#define ll long long
#define ld long double

using namespace std;

int solve(vector<int> &v,int start,int end,int k)
{
	
}

int main()
{
	fio
	int TC;
	cin>>TC;
	//TC=1;
	while(TC--)
	{
		int n,k,x;
		cin>>n>>k>>x;
		vector<ll> dp(n+1,0);
		dp[0]=0;
		dp[1]=1;
		for(int i=2;i<n;i++)
			dp[i]=(k-2)*dp[i-1]+(k-1)*dp[i-2];
		(x==1)?cout<<(k-1)*dp[n-2]:cout<<dp[n-1]<<endl;
		
	}
	return 0;
}
