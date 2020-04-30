#include <bits/stdc++.h>
using namespace std;

int countDel(vector<int> &v,int n,unordered_map<int,int> &h1,unordered_map<int,int> &h2)
{
	int ans=0;
	set<int> s;
	for(int i=0;i<n;i++)
		s.insert(v[i]);
	for(auto it:s)
		ans+=min(h1[it],h2[it]);
	return ans;
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,m;
		cin>>n>>m;
		vector<int> v1(n),v2(m);
		unordered_map<int,int> h1,h2;

		for(int i=0;i<n;i++)
			cin>>v1[i],h1[v1[i]]++;
		for(int i=0;i<m;i++)
			cin>>v2[i],h2[v2[i]]++;
		if(m>n)
			cout<<countDel(v1,n,h1,h2)<<endl;
		else
			cout<<countDel(v2,m,h1,h2)<<endl;

	}
	return 0;
}