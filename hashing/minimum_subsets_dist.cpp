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
		unordered_map<int,int> hash;
		int mx_freq=0;
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			hash[v[i]]++;
			mx_freq=max(mx_freq,hash[v[i]]);
		}
		cout<<mx_freq<<endl;
	}
	return 0;
}