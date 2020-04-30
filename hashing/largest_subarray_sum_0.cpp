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
		vector<int> v(n+1,0);
		for(int i=1;i<=n;i++)
			cin>>v[i],v[i]+=v[i-1];

		unordered_map<int,int> hash;
		int mx_len=0;
		for(int i=0;i<=n;i++)
		{
			if(hash.find(v[i])!=hash.end())
				mx_len = max(mx_len,i-hash[v[i]]);
			else
				hash[v[i]]=i;
		}
		cout<<mx_len<<endl;
	}
	return 0;
}