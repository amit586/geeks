#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define f(i,j,k)  for(int i=j;i<k;i++)
#define fr(i,j,k) for(int i<=k-1;i>=j;i--)
#define ll long long
#define ld long double
#define MAX 100000000

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
		std::vector<int> v(n);
		for (int i = 0; i < n; ++i)
			cin>>v[i];
		
		vector<int> dp(n);
		dp[n-1]=1;
		for(int i=n-2;i>=0;i--)
		{
			
			if(i+v[i]>=n-1)
				dp[i] = 1;
			else
			{
				int mn = MAX;
				for(int j=i+1;j<=i+v[i];j++)
				{
					mn = min(mn,dp[j]);
				}
				dp[i] = 1+mn;
			}
		}
		// cout<<endl;
		// for(int i=0;i<n;i++)
		// 	cout<<dp[i]<<" ";
		// cout<<endl;
		cout<<(dp[0]<MAX?dp[0]:-1)<<endl;	
	}
	return 0;
}
