#include<bits/stdc++.h>
#define pb push_back
#define MAX 1000
using namespace  std;


int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		vector <int> v;
		int temp;
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			v.pb(temp);
		}
		int dp[n+1];
		memset(dp,0,sizeof(dp));
		cout<<lis(v,1,0,n)+1<<endl;	
	}
	return 0;
}
