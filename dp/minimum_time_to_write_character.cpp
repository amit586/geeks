#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define f(i,j,k)  for(int i=j;i<k;i++)
#define fr(i,j,k) for(int i<=k-1;i>=j;i--)
#define ll long long
#define ld long double
#define INF (int)1e7
using namespace std;

int main()
{
	fio
	int TC;
	cin>>TC;
	//TC=1;
	while(TC--)
	{
		int n,I,D,C;
		cin>>n>>I>>D>>C;
		std::vector<int> dp(n+1);
		dp[0] = INF;
		dp[1]= I;
		for (int i = 2; i <= n; ++i)
		{
			int x2;
			if(i%2==0)
				x2 = dp[i/2]+C;
			else
				x2 = min(dp[(i-1)/2]+C+I,dp[(i+1)/2]+C+D);
			dp[i] = min(dp[i-1]+I,x2);
		}
		cout<<dp[n]<<endl;
		
	}
	return 0;
}
