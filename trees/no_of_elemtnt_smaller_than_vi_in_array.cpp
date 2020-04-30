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
		multiset <int> m;
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			m.insert(v[i]);
		}

		for(int i=1;i<n-1;i++)
		{
			cout<<i<<endl;
			cout<<"elements smaller than i are "<<distance(m.begin(),m.lower_bound(v[i]))<<endl;
			cout<<"elements greater than i are "<<distance(m.upper_bound(v[i]),m.end())<<endl;
		}
	}
	return 0;
}