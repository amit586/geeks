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
		vector<int64_t> v(max(n+1,2),0);
		v[0]=0;
		v[1]=1;
		unordered_set<int> hash;
		hash.insert(0);
		for(int i=2;i<=n;i++)
		{
			v[i]=v[i-1]-i;
			if(v[i]<0 || hash.find(v[i])!=hash.end())
				v[i]=v[i-1]+i;
			hash.insert(v[i]);
		}
		for(int i=0;i<=n;i++)
			cout<<v[i]<<" ";
		cout<<endl;
	}
	return 0;
}