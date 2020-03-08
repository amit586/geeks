#include <bits/stdc++.h>
#define MAX 10000
#define D 1000000007

using namespace std;

long long dp[MAX];

void fibo(int n)
{
    dp[0]=0;
    dp[1]=1;
    
    for(int i=2;i<=n;i++)
    {
        dp[i]=(dp[i-1]%D+dp[i-1]%D)%D;
    }
}

int main() {
	int t;
	cin>>t;
	int arr[t],mx=INT_MIN;
	for(int i=0;i<t;i++)
	{
	    cin>>arr[i];
	    mx = max(mx,arr[i]);
	}
	fibo(mx);
	for(int i=0;i<t;i++)
	{
	    cout<<dp[arr[i]]<<endl;
	}
	return 0;
}