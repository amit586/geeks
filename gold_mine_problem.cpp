#include<iostream>
#include<algorithm>
using namespace std;

int max(int a,int b, int c)
{
	int arr[3];
	arr[0]=a;
	arr[1]=b;
	arr[2]=c;
	sort(arr,arr+3);
	return arr[2];
}


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,n;
		cin>>n>>m;
		int arr[n+2][m+1]={0};
		int dp[n+2][m+1]={0};

		for(int i=0;i<n+2;i++)
		{
			for(int j=0;j<m+1;j++)
				arr[i][j]=dp[i][j]=0;
		}


		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>arr[i][j];
			}

		}


		for(int j=1;j<=m;j++)
		{
			for(int i=1;i<=n;i++)
			{
				dp[i][j]=arr[i][j]+max(dp[i-1][j-1],dp[i][j-1],dp[i+1][j-1]);
				//cout<<i<<" "<<j<<" "<<arr[i][j]<<" "<<dp[i-1][j-1]<<" "<<dp[i][j-1]<<" "<<dp[i+1][j-1]<<endl;
			}
		}
		
		int mx = 0;
		for(int i=1;i<=n;i++)
		{
			if(dp[i][m]>mx)
				mx=dp[i][m];
		}
		cout<<mx<<endl;

	}
	return 0;
}
