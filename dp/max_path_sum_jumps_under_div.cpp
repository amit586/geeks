#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define f(i,j,k)  for(int i=j;i<k;i++)
#define fr(i,j,k) for(int i<=k-1;i>=j;i--)
#define ll long long
#define ld long double

using namespace std;

void printPath(vector<int> &v,int n)
{
	vector<int> dp(n);
	dp[0]=v[0];
	dp[1] = v[0]+v[1];

	for(int i=2;i<n;i++)
	{
		vector<int> factors;

		for(int j=1;j<=sqrt(i+1);j++)
		{
			if((i+1)%j==0)
				factors.push_back(j);
		} 

		int mx = INT_MIN;
		//cout<<i+1<<" : ";
		for(int j=0;j<factors.size();j++)
		{
			//cout<<factors[j]<<" ";
			mx = max(mx,dp[factors[j]-1]);
		}
		//cout<<endl;
		dp[i] = mx+v[i];
	}
	for(int i=0;i<n;i++)
		cout<<dp[i]<<" ";
	cout<<endl;
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
		std::vector<int> v(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
		}
		printPath(v,n);
	}
	return 0;
}
