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
		unordered_map<int,bool> vis;
		unordered_map<int,int> freq;
		for(int i=0;i<n;i++)
			cin>>v[i],freq[v[i]]++,vis[v[i]]=false;
		int cf=0;
		//sort(v.begin(),v.end());
		for(int i=0;i<n;i++)
		{
			if(!vis[v[i]])
			{
				vis[v[i]]=true;
				cf+=freq[v[i]];
				cout<<cf<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}