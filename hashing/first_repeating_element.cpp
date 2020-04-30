#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> v(n);
		unordered_set<int> s;
		int frep=-1;
		for(int i=0;i<n;i++)
			cin>>v[i];
		for(int i=n-1;i>=0;i--)
		{
			if(s.find(v[i])!=s.end())
				frep=i+1;
			else
				s.insert(v[i]);
		}
		cout<<frep<<endl;
	}
	return 0;
}