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
		for(int i=0;i<n;i++)
			cin>>v[i];
		unordered_set <int> s;
		bool found=false;
		for(int i=0;i<n;i++)
		{
			if(s.find(v[i])!=s.end())
			{
				found=true;
				break;
			}
			s.insert(v[i]);
			if(i>k)
				s.erase(v[i-k]);
		}
		cout<<found<<endl;
	}
	return 0;
}