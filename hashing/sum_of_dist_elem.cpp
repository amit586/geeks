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
		unordered_set<int>s;
		for(int i=0;i<n;i++)
			cin>>v[i],s.insert(v[i]);
		int sum=0;
		for(auto it:s)
			sum+=it;
		cout<<sum<<endl;
	}
	return 0;
}