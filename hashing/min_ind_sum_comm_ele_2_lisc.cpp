#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,m;
		cin>>n>>m;
		vector<string> l1(n),l2(m);
		unordered_map<string,int> hash;
		priority_queue<pair<int,string>> common;
		for(int i=0;i<n;i++)
			cin>>l1[i],hash[l1[i]]=i;
		int mn=INT_MAX;
		for(int i=0;i<m;i++)
		{
			cin>>l2[i];
			if(hash.find(l2[i])!=hash.end())
			{
				common.push({hash[l2[i]]+i,l2[i]});
				mn = min(mn,hash[l2[i]]+i);
			}
		}
		while(!common.empty() && mn==common.top().first)
		{
			cout<<common.top().first<<" "<<common.top().second<<endl;
			common.pop();
		}

	}
	return 0;
}