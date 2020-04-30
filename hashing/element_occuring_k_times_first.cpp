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
		vector<int> v(n);
		unordered_map<int,int> m;
		int ele=-1;
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			m[v[i]]++;
		}
		for(int i=0;i<n;i++)
			if(m[v[i]]>=k)
			{
				ele = v[i];
				break;
			}
		cout<<ele<<endl;
	}
	return 0;
}