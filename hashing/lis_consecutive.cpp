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
		std::vector<int> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		unordered_map<int,int> lis;
		int mx=0;
		for(int i=0;i<n;i++)
		{
			if(lis.find(v[i]-1)!=lis.end())
				lis[v[i]]=lis[v[i]-1]+1;
			else
				lis[v[i]]=1;
			mx = max(mx,lis[v[i]]);
		}
		cout<<mx<<endl;
	}
	return 0;
}