#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	long long dp[n+1]={0};
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	dp[3]=2;
	for(int i=4;i<=n;i++)
	{
//		1 + a(n + 1 – a(a(n)))
		dp[i]= 1+ dp[i-dp[dp[i-1]]];
	}
	for(int i=0;i<=n;i++)
		cout<<dp[i]<< ' ';
	cout<<endl;
	
	return 0;
	
}
