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
		vector<pair<int,int>> v(n);
		unordered_map<int,int> freq;
		vector<int> ans(n);
		for(int i=0;i<n;i++)
		{
			cin>>v[i].first;
			if(freq.count(v[i].first)==0)
				v[i].second=1;
			else
				v[i].second=0;
			freq[v[i].first]++;
		}

		int j=0;
		for(int i=0;i<n;i++)
		{
			if(v[i].second==1)
			{
				while(freq[v[i].first])
					cout<<v[i].first<<" ",freq[v[i].first]--;
			}
		}
	}
	return 0;
}