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
		unordered_map<int,int> freq;
		vector<int> v(n);
		priority_queue<pair<int,int>> pq;
		for(int i=0;i<n;i++)
			cin>>v[i],freq[v[i]]++;
		for(auto it:freq)
			pq.push({it.second,it.first});
		while(k--)
			cout<<pq.top().second<<" ",pq.pop();
		cout<<endl;
	}
	return 0;
}