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
		unordered_map<int,int> m;
		int x,y;
		vector<pair<int,int>> sym;
		for(int i=0;i<n;i++)
		{
			cin>>x>>y;
			if(m[y]==x)
				sym.push_back({x,y});
			else
				m[x]=y;
		}

		for(int i=0;i<sym.size();i++)
			cout<<sym[i].second<<" "<<sym[i].first<<endl;
		cout<<endl;
	}
	return 0;
}