#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,m,x;
		cin>>n>>m>>x;
		unordered_map<int,int> hash;
		vector<int> v1(n),v2(m);
		for(int i=0;i<n;i++)
			cin>>v1[i];
		for(int i=0;i<m;i++)
			cin>>v2[i],hash[v2[i]]++;
		//cout<<pairs<<endl;
		vector<pair<int,int>> ans;
		for(int i=0;i<n;i++)
			if(hash.find(x-v1[i])!=hash.end())
				ans.push_back({v1[i],x-v1[i]});
		if(ans.size()==0)
			cout<<-1<<endl;
		else
		{
			cout<<ans[0].first<<" "<<ans[0].second;
			for(int i=1;i<ans.size();i++)
				cout<<","<<ans[i].first<<" "<<ans[i].second;
		}
	}
	return 0;
}