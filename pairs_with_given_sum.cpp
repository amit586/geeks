#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,k;
		cin>>n>>k;
		vector<int> v(n);
		unordered_map<int,int> m;
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			m[v[i]]++;
		}

		int ans=0;
		for(int i=0;i<n;i++)
			ans+=m[k-v[i]];
		cout<<ans/2<<endl;
	}
	return 0;
}