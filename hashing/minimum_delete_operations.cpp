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
		int mx=0;
		unordered_map<int,int> m;
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			m[v[i]]++;
			mx = max(mx,m[v[i]]);
		}
		cout<<n-mx<<endl;

	}
	return 0;
}