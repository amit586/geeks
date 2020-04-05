#include <bits/stdc++.h>
using namespace std;

void printchain(vector<pair<int,int>> &v,int n)
{
	vector <pair<int,int>> dp[n+1];
	for(int i=1;i<=n;i++)
		dp[i].push_back(v[i-1]);
	int mx_sz=1,mx_sz_i=1;
	for(int i=1;i<=n;i++)
	{
		int mx_ind=-1,mx_size=1;
		for(int j=1;j<i;j++)
			if(v[j-1].second<v[i-1].first)
				if(dp[j].size()>=mx_size)
				{
					mx_size=dp[j].size();
					mx_ind=j;
				}
		if(mx_ind!=-1)
			dp[i].insert(dp[i].end(),dp[mx_ind].begin(),dp[mx_ind].end());	
		if(mx_sz<dp[i].size())
		{
			mx_sz=dp[i].size();
			mx_sz_i=i;
		}
	}
	cout<<endl;
	// for(int i=0;i<=n;i++)
	// {
		for(auto it:dp[mx_sz_i])
			cout<<"{"<<it.first<<","<<it.second<<"} ";
		cout<<endl;
	//}
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
			v[i]={temp1,temp2};
		}
		sort(v.begin(),v.end(),[](const pair<int,int> &p1,const pair<int,int> &p2)->bool
			{return p1.first<p2.first;});
		printchain(v,n);
	}
	return 0;
}
/*
1
5
2 24
39 60
15 28
27 40
50 90
*/

