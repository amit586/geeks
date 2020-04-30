#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define f(i,j,k)  for(int i=j;i<k;i++)
#define fr(i,j,k) for(int i<=k-1;i>=j;i--)
#define ll long long
#define ld long double
#define MAX 300
using namespace std;

int dp[MAX][MAX];

int removal(const vector<int> &v,int n,int k,int i,int j)
{
	if(i<0 || i>=n || j<0 || j>n)
		return 0;
	if((v[j]-v[i])<=k)
		return 0;
	else if(dp[i][j]!=0)
		return dp[i][j];
	else
	{
		dp[i][j]= 1+min(removal(v,n,k,i+1,j),removal(v,n,k,i,j-1));
		return dp[i][j];
	}
}

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
		std::vector<int> v(n);
		memset(dp,0,sizeof(dp));
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		cout<<removal(v,n,k,0,n-1)<<endl;
		
	}
	return 0;
}
