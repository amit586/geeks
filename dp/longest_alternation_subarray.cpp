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
		std::vector<ll> v(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
		}
		vector<int> dp(n,1);
		for(int i=n-2;i>=0;i--)
		{
			if((v[i]>=0 && v[i+1]<0)||(v[i]<0 && v[i+1]>=0))
				dp[i]=1+dp[i+1];
		}
		for(int i=0;i<n;i++)
			cout<<dp[i]<<" ";
		cout<<endl;		
	}
	return 0;
}
