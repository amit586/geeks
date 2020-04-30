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
		unordered_map<int,int> freq(n);
		int mx=INT_MIN;
		int count=0;
		vector<int> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i],freq[v[i]]++,mx=max(mx,v[i]);
		vector<bool> vis(n,false);
		for(int i=0;i<n;i++)
			for(int j=0;j<mx;j+=v[i])
				if(freq.find(j+k)!=freq.end() && !vis[j])
					count++,vis[j]=true;
		cout<<count<<endl;
	}
	return 0;
}