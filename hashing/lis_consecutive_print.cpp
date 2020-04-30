#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		unordered_map<int,vector<int>> m;
		int mx,e_mx;
		mx=0;
		for(int i=0;i<n;i++)
		{
			if(m.find(v[i]-1)!=m.end())
				m[v[i]].insert(m[v[i]].end(),m[v[i]-1].begin(),m[v[i]-1].end()),m[v[i]].push_back(v[i]);
			else
				m[v[i]].clear(),m[v[i]].push_back(v[i]);
			if(m[v[i]].size()>mx)
				mx = m[v[i]].size(),e_mx=v[i];
		}
		if(mx!=0)
			for(auto it:m[e_mx])
				cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}