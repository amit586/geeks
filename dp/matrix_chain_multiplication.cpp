#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define f(i,j,k)  for(int i=j;i<k;i++)
#define fr(i,j,k) for(int i<=k-1;i>=j;i--)
#define ll long long
#define ld long double
#define MAX 300 
using namespace std;

//ll dp[MAX][MAX];


ll minOperations(const vector<int> &v,int n)
{
	// if(i>=j)
	// {
	// 	dp[i][j]=0;
	// 	return 0;
	// }
	// else if(dp[i][j]!=-1)
	// 	return dp[i][j];
	// else
	// {
	// 	int mn = INT_MAX;
	// 	int count;
	// 	for(int k=i;k<j;k++)
	// 	{
	// 		count = minOperations(v,n,i,k)+minOperations(v,n,k+1,j) + v[i-1]*v[k]*v[j];
	// 		mn = min(mn,count);
	// 	}
	// 	dp[i][j]=mn;
	// 	return dp[i][j];
	// }

	////////////      loop version   ////////

	int dp[n][n];
	for(int i=0;i<n;i++)
		dp[i][i]=0;
	for(int L = 2;L<n;L++)
	{
		for(int i=1;i<n-L+1;i++)
		{
			int j = i+L-1;
			dp[i][j]=INT_MAX;
			for(int k=i;k<j;k++)
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+v[i-1]*v[k]*v[j]);
		}
	}
	return dp[1][n-1];

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
		//memset(dp,0,sizeof(dp));
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
		}
		cout<<minOperations(v,n)<<endl;
		
	}
	return 0;
}
