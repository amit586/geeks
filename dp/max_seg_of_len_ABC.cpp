#include <bits/stdc++.h>
using namespace std;

int max(int a,int b,int c)
{
	return max(a,max(b,c));
}

int maxSegement(int n,int a,int b,int c)
{
	// if(n==0)
	// 	return 0;
	// else if(n<0)
	// 	return INT_MIN;
	// else
	// 	return 1+max(maxSegement(n-a,a,b,c),maxSegement(n-b,a,b,c),maxSegement(n-c,a,b,c));

	vector <int> dp(n+1,INT_MIN);
	dp[0]=0;

	for(int i=1;i<=n;i++)
	{
		int x=INT_MIN,y=INT_MIN,z=INT_MIN;
		if(i-a>=0)
			x = dp[i-a];
		if(i-b>=0)
			y  = dp[i-b];
		if(i-c>=0)
			z = dp[i-c];
		dp[i]=max(x,y,z)+1;

	}
	return dp[n];
	
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	
	while(tc--)
	{
		int n, a[3];
		cin>>n>>a[0]>>a[1]>>a[2];
		sort(a,a+3);
		cout<<maxSegement(n,a[0],a[1],a[2])<<endl;
	}
	return 0;
}