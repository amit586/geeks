#include <cstring>
#include <iostream>
#define MAX 500
#define ll long long
using namespace std;

ll count(ll n , ll diff, ll dp[][MAX])
{

	if(abs(diff)>n)
		return 0;
	if(n==1)
		if(abs(diff)==1)
			return 1;
		else if(diff==0)
			return 2;
	if(dp[n][diff]!=0)
		return dp[n][diff];
	dp[n][diff]= 2*count(n-1,diff,dp) + count(n-1,diff+1,dp) + count(n-1,diff-1,dp);
	return dp[n][diff];

}


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		ll dp[n+1][MAX];
		memset(dp,0,sizeof(dp));
		cout<<count(n,0,dp)<<endl;
	}
	return 0;
}