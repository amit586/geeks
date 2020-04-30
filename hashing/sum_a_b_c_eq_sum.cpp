#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,m,o,sum;
		cin>>n>>m>>o>>sum;
		unordered_set <int> hash;
		vector<int>v1(n),v2(m),v3(o);
		for(int i=0;i<n;i++)
			cin>>v1[i];
		for(int i=0;i<m;i++)
			cin>>v2[i];
		for(int i=0;i<o;i++)
			cin>>v3[i],hash.insert(v3[i]);
		bool found=false;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				if(hash.find(sum-v1[i]-v2[j])!=hash.end())
				{
					found =true;
					break;
				}
			if(found)
				break;
		}
		cout<<found<<endl;
	}
	return 0;
}