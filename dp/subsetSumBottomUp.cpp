#include <bits/stdc++.h>
using namespace std;

bool subsetSum(vector <int> &v ,int n,int sum)
{
	bool dp[2][sum+1];
	memset(dp,0,sizeof(dp));

	//cout<<n<<" "<<sum<<endl;

	for(int i=0;i<=n;i++)
		dp[i%2][0]=true;
	for(int i=1;i<=sum;i++)
		dp[0][i]=false;


	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(j>v[i])
				dp[i%2][j]=dp[(i-1)%2][j];
			else
				dp[i%2][j]=dp[(i-1)%2][j]||dp[(i-1)%2][j-v[i-1]];
		}
	}
	
	// for(int i=0;i<=n;i++)
	// {
	// 	for(int j=0;j<=sum;j++)
	// 		cout<<(int)dp[i][j]<<" ";
	// 	cout<<endl;
	// }
	return dp[n%2][sum];
}

int main(int argc, char const *argv[])
{
	int n,k;
	cin>>n>>k;
	vector <int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	sort(v.begin(),v.end());
	cout<<subsetSum(v,n,k)<<endl;
	
	return 0;
}