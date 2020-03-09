#include<iostream>
#include<cstring>
#define NUM_STATION 2
#define MAX 2
using namespace std;
int carAssembly(int a[][MAX],int t[][MAX],int e[],int x[],int n)
{
	int dp[n+1][2];
	memset(dp,0,sizeof(dp));
	dp[n][0]=x[0];
	dp[n][1]=x[1];
	dp[n-1][0]=dp[n][0]+a[n-1][0];
	dp[n-1][1]=dp[n][1]+a[n-1][1];
//	cout<<"dp["<<n-1<<"][0] "<<dp[n-1][0]<<" dp["<<n-1<<"][1] "<<dp[n-1][1]<<endl;
	for(int i=n-2;i>=0;i--)
	{
		dp[i][0] =a[i][0] + min(dp[i+1][0],t[i+1][0] + dp[i+1][1]);
		dp[i][1] = a[i][1] + min(dp[i+1][1],t[i+1][1] + dp[i+1][0]);
//		cout<<"dp["<<i<<"][0] "<<dp[i][0]<<" dp["<<i<<"][1] "<<dp[i][1]<<endl;
	}
//	cout<<dp[0][0] + e[0]<<" "<<dp[1][0]+e[1]<<endl;
	return min(dp[0][0] + e[0],dp[0][1]+e[1]);
}
int main()
{
	int a[][NUM_STATION] = {{4,2},{5,10},{3,1},{2,4}};
    int t[][NUM_STATION] = {{0,0},{7,9},{4,2},{5,8}} ;
    int e[] = {10, 12}, x[] = {18, 7};  
    cout << carAssembly(a, t, e, x,4)<<endl;  
    return 0;
}
