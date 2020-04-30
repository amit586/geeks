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
		n;
		vector<int> dp(n+1);
		dp[0]=0;
		dp[1]=1;
		dp[2]=1;

		for(int i=3;i<=n;i++)
			dp[i] = (i%2==0?dp[i/2]:(dp[(i-1)/2]+dp[(i+1)/2]));
		f(i,0,n+1)
			cout<<dp[i]<<" ";
		cout<<endl;
	}
	return 0;
}
