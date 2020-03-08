#include <bits/stdc++.h>
using namespace std;

bool isSubset_dp(std::vector<int> v,int n,int sum)
{
	bool dp[n+1][sum+1];
	for(int i=0;i<n+1;i++)
		dp[i][0]=true;
	for(int i=0;i<sum+1;i++)
		dp[0][i]=false;

	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(v[i]>j)
				dp[i][j]=dp[i-1][j];
			else
			{
				dp[i][j]=dp[i-1][j]||dp[i-1][j-v[i-1]];
			}
		}
	}

	return dp[n][sum];
}

bool isSubset(std::vector<int> v,int n,int sum)
{
	if(sum==0)
		return true;
	else if(sum < 0 || (sum>0 && n==0))
		return false;
	else
		return isSubset(v,n-1,sum)||isSubset(v,n-1,sum-v[n-1]);
}


int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,temp,sum=0;
		vector <int> a;
		cin>>n;
	
		for(int i = 0; i < n; ++i)
		{			
			cin>>temp;
			sum+=temp;
			a.push_back(temp);
		}

		// if(sum%2==1)
		// {
		// 	cout<<"NO\n";
		// 	continue;
		// }
		sum/=2;
		isSubset(a,n,sum)?cout<<"YES\n":cout<<"NO\n";			

	}
	return 0;
}