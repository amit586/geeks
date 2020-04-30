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
		vector<int> v1(n),v2(m);
		unordered_map<int,int> hash;
		
		for(int i=0;i<n;i++)
			cin>>v1[i];

		for(int i =0;i<m;i++)
			cin>>v2[i],hash[v2[i]]++;
		
		vector<int> ans;

		for(int i=0;i<n;i++)
			if(hash.find(v1[i])==hash.end())
				ans.push_back(v1[i]);

		for(int i=0;i<ans.size();i++)
			cout<<ans[i]<<" ";

		cout<<endl;
	}
	return 0;
}