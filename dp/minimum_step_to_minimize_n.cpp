#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define f(i,j,k)  for(int i=j;i<k;i++)
#define fr(i,j,k) for(int i<=k-1;i>=j;i--)
#define ll long long
#define ld long double

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
		// std::vector<int> v(n);
		// for (int i = 0; i < n; ++i)
		// {
		// 	cin>>v[i];
		// }
		vector<int> dp(n+1);
		dp[0]=0;
		dp[1]=0;
		dp[2]=dp[3]=1;
		for(int i=3;i<=n;i++)
		{
			int a=INT_MAX,b=INT_MAX;
			if(i%2==0)
				a = dp[i/2];
			if(i%3==0)
				b = dp[i/3];

			dp[i] = 1+min(a,min(b,dp[i-1]));
		}		
		cout<<dp[n]<<endl;
	}
	return 0;
}
