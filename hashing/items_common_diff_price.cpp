#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,m;
		cin>>n>>m;
		unordered_map<string,int> l1;
		vector<pair<string,int>> l2;

		string item;
		int price;
		for(int i=0;i<n;i++)
		{
			cin>>item>>price;
			l1[item]=price;
		}

		for(int i=0;i<m;i++)
		{
			cin>>item>>price;
			if(l1[item]>0 && l1[item]!=price)
				l2.push_back({item,price});

		}
		for(int i=0;i<l2.size();i++)
			cout<<l2[i].first<<" "<<l2[i].second;
	}
	return 0;
}