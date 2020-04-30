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
		unordered_map<int,int> m;
		int mx=INT_MIN;
		int count=0;
		for(int i=0;i<n;i++)
			cin>>v[i],m[v[i]]++,mx=max(mx,v[i]);

		for(int i=0;i<n;i++)
			for(int j=1*v[i];j*v[i]<=mx;j++)
				if(j==1 && m.count(v[i])>=2)
					count++;
				else if(j!=1 && m.find(j*v[i])!=m.end())
					count++;
		cout<<count<<endl;
	}
	return 0;
}