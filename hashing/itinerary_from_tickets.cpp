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
		unordered_map<string,string> nxt,pre;
		vector<pair<string,string>> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i].first>>v[i].second,nxt[v[i].first]=v[i].second,pre[v[i].second]=v[i].first;

		list <string> route;
		route.push_back(v[0].first);
		string next=v[0].second;
		while(next.size()>0)
		{
			route.push_back(next);
			if(nxt.find(next)==nxt.end())
				next="";
			else
				next=nxt[next];
		}
		string prev=(pre.find(v[0].first)==pre.end()?"":pre[v[0].first]);
		while(prev.size()>0)
		{
			route.push_front(prev);
			if(pre.find(prev)!=pre.end())
				prev=pre[prev];
			else
				prev="";
		}

		for(auto it:route)
			cout<<it<<"->";
		cout<<endl;


	}
	return 0;
}