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
		vector<int> a(n),b(m);
		unordered_map<int,int> hash;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			hash[a[i]]++;
		}
		bool isSubset=true;
		for(int i=0;i<m;i++)
		{
			cin>>b[i];
			//cout<<"hash bi"<<hash[b[i]]<<endl;
			if(hash[b[i]]==0)
				isSubset=false;
		}
		cout<<(isSubset?"Yes\n":"No\n");
	}
	return 0;
}