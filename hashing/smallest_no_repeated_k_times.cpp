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
		for(int i=0;i<n;i++)
			cin>>v[i],m[v[i]]++;
		int ans=INT_MAX;
		for(int i=0;i<n;i++)
			if(m[v[i]]==k && v[i]<ans)
				ans=v[i];
		cout<<(ans==INT_MAX?-1:ans)<<endl;
	}
	return 0;
}