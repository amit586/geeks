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
		int n,k;
		cin>>n>>k;
		std::vector<ll> v;
		int temp;
		for (int i = 0; i < n; ++i)
		{
			cin>>temp;
			if(temp!=0)
				v.push_back(temp);
		}
		n = v.size();
		vector<ll> dp(k+1,0);
		dp[0]=1;
		for(int i=1;i<=k;i++)
		{
			int ways = 0;
			for(int j=0;j<n;j++)
			{
				if((i>=v[j]))
					dp[i]+=dp[i-v[j]];
			}
			
		}
		cout<<dp[k]<<endl;		
	}
	return 0;
}

