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
		unordered_map<int,pair<int,int>> um;
		bool found=false;

		for(int i=0;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(um.find(v[i]+v[j])!=um.end())
					{	found =true;break;}
				um[v[i]+v[j]]={v[i],v[j]};
			}
			if(found)
				break;
		}
		cout<<found<<endl;
	}
	return 0;
}