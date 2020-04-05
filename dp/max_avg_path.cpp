#include <bits/stdc++.h>
#define MAX 100
using namespace std;

bool canMove(int n,int x,int y)
{
	return ((x>=0 && x<n && y>=0 && y<n)?true:false);
}



float maxavg(int arr[][MAX],int n)
// float maxavg(int arr[][MAX],int n,int i,int sum,int x,int y)
{
	// if(x==y && y==n-1)
	// {	
	// 	//cout<<sum<<" "<<i<<endl;
	// 	return ((float)sum/(float)i);
	// }
	// else 
	// {
	// 	float x1=0.0,x2=0.0;
	// 	if(canMove(n,x+1,y))
	// 		x1 = maxavg(arr,n,i+1,sum+arr[x+1][y] ,x+1,y);
	// 	if(canMove(n,x,y+1))
	// 		x2 = maxavg(arr,n,i+1,sum+arr[x][y+1],x,y+1);
	// 	return max(x1,x2);
	// }

	int dp[n][MAX];
	dp[0][0]=arr[0][0];
	for(int i=1;i<n;i++)
	{	
		dp[0][i]=arr[0][i] +dp[0][i-1];
		dp[i][0]=arr[i][0] +dp[i-1][0];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			dp[i][j]= arr[i][j]+max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return ((float)dp[n-1][n-1]/(float)(2*n-1));
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		int arr[n][MAX];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>arr[i][j];
		//cout<<maxavg(arr,n,1,arr[0][0],0,0)<<endl;
		cout<<maxavg(arr,n)<<endl;
	}	
	return 0;
}