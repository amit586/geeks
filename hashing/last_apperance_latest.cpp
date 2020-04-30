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
		vector<int> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		unordered_map<int,int> last;
		int mx=0;
		for(int i=0;i<n;i++)
		{
			if(last.count(v[i])>0)
				last[v[i]]=-1;
			else
				last[v[i]]=i;
			
		}
		for(auto it:last)
			mx= max(mx,it.second);
		cout<<v[mx]<<endl;
	}
	return 0;
}