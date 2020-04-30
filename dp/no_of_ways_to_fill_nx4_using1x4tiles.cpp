#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define f(i,j,k)  for(int i=j;i<k;i++)
#define fr(i,j,k) for(int i<=k-1;i>=j;i--)
#define ll long long
#define ld long double
#define P 1000000007
using namespace std;

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
		if(n<4)
		{
			cout<<1<<endl;
			continue;
		}
		else if(n==4)
		{
			cout<<2<<endl;
			continue;
		}
		vector<ll> dp(n+1,0);
		dp[0]=0;
		for (int i = 1; i <=n; ++i)
		{
			if(i<4)
				dp[i]=1;
			else if(i>4)
				dp[i] = (dp[i-1]+dp[i-4])%P;
			else
				dp[i]=2;
		}
		cout<<dp[n]<<endl;
		
	}
	return 0;
}
