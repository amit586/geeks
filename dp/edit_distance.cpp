#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define f(i,j,k)  for(int i=j;i<k;i++)
#define fr(i,j,k) for(int i<=k-1;i>=j;i--)
#define ll long long
#define ld long double
#define INF 1000000
using namespace std;

int countEdit(const string &str1,const string &str2,int n,int m)
{
	// if(n==0)
	// 	return m;
	// else if(m==0)
	// 	return n;
	// else if(str1[n-1]==str2[m-1])
	// {
	// 	return countEdit(str1,str2,n-1,m-1);
	// }
	// else if(str1[n-1]!=str2[m-1])
	// {
	// 	return 1 + min(countEdit(str1,str2,n-1,m),min(countEdit(str1,str2,n-1,m-1),countEdit(str1,str2,n,m-1)));
	// }

	vector <vector<int>> dp(n+1,vector<int>(m+1,0));

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i==0)
				dp[i][j]=j;
			else if(j==0)
				dp[i][j]=i;
			else if(str1[i-1]==str2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = 1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
		}
	}
	return dp[n][m];
	
}

int main()
{
	fio
	int TC;
	cin>>TC;
	//TC=1;
	while(TC--)
	{
		int x,y;
		cin>>x>>y;
		string str1,str2;
		cin>>str1>>str2;
		int i = 0,j=0;
		cout<<countEdit(str1,str2,x,y)<<endl;
		
	}
	return 0;
}
