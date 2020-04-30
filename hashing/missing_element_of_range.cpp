#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,l,r;
		cin>>n>>l>>r;
		vector<int> v(n);
		int hash[r-l]={0};
		for(int i=0;i<n;i++)
		{	
			cin>>v[i];
			if(v[i]>=l && v[i]<r)
				hash[v[i]-l]++;
		}
		for(int i=0;i<r-l;i++)
			if(hash[i]==0)
				cout<<l+i<<" ";
		cout<<endl;

	}
	return 0;
}