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
		int mx=0;
		unordered_map<int,int> m;
		for(int i=0;i<n;i++)
		{
			m[v[i]]=1;
			if(m.find(v[i]-1)!=m.end())
				m[v[i]]=1+m[v[i]-1];
			if(m.find(v[i]+1)!=m.end())
				m[v[i]]=max(m[v[i]],1+m[v[i]+1]);
			mx = max(m[v[i]],mx);
		}
		cout<<mx<<endl;
	}
	return 0;
}