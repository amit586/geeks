#include <bits/stdc++.h>
using namespace std;

int chainPair(vector <pair<int,int>> &v,int n)
{
	vector <int> dp(n+1,1);

	int ans=INT_MIN;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
			if(v[j-1].second<v[i-1].first)
				dp[i]=max(dp[i],dp[j]+1);
		ans = max(dp[i],ans);
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;

		vector<pair<int,int>> v(n);
		int temp1,temp2;
		for(int i=0;i<n;i++)
		{
			cin>>temp1>>temp2;
			v[i]=make_pair(temp1,temp2);
		}

		sort(v.begin(),v.end(),[](const pair<int,int> &p1,const pair<int,int> &p2)->bool
						{
							return p1.first<p2.first;
						});

		// for(int i=0;i<v.size();i++)
		// {
		// 	cout<<v[i].first<<" "<<v[i].second<<endl;
		// }
		cout<<chainPair(v,n)<<endl;
	}
	return 0;
}