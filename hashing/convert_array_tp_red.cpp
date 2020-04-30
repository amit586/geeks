#include<bits/stdc++.h>
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
		vector<pair<int,int>> loc(n);
		for(int i=0;i<n;i++)
			cin>>v[i],loc[i]={v[i],i};
		sort(loc.begin(),loc.end(),[](const pair<int,int> &p1,const pair<int,int> &p2)->bool{
			return p1.first<p2.first;
		});
		for(int i=0;i<n;i++)
			v[loc[i].second]=i;
		for(int i=0;i<n;i++)
			cout<<v[i]<<" ";
		cout<<endl;
	}
	return 0;
}