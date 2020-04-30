#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define f(i,j,k)  for(int i=j;i<k;i++)
#define fr(i,j,k) for(int i<=k-1;i>=j;i--)
#define ll long long
#define ld long double

using namespace std;

int LIS(vector<ll> &v,int n)
{
	int dp[n]={0};
	int ans=INT_MIN;
	for(int i=0;i<n;i++)
	{
		int mx = 0;
		for(int j=0;j<i;j++)
		{
			if(v[j]<v[i] && (v[i]-v[j])>=(i-j))
				mx = max(mx,dp[j]) ;
		}
		dp[i] = 1+mx;
		ans = max(dp[i],ans);
	}
	return ans;
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
		std::vector<ll> v(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
		}

		int lis = LIS(v,n);
		//cout<<lis<<endl;
		cout<<n-lis<<endl;
		
	}
	return 0;
}
