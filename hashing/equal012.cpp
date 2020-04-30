#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		string s;
		cin>>s;
		int n=s.size();
		vector<int> v(n+1,0);
		
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='0' )
				v[i]=-1;
			else if(s[i-1]=='1')
				v[i]=-2;
			else
				v[i]=3;
			v[i]=v[i]+v[i-1];
		}
		for(int i=0;i<=n;i++)
			cout<<v[i]<<" ";
		cout<<endl;

		unordered_map<int,int> hash(n);
		int count=0;
		for(int i=0;i<=n;i++)
		{
			if(hash.find(v[i])==hash.end())
				hash[v[i]]=1;
			else
				count+=hash[v[i]],hash[v[i]]++;
			cout<<"hash:"<<v[i]<<" "<<hash[v[i]]<<endl;
		}
		cout<<count<<endl;

	}
	return 0;
}