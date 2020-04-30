#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,r;
		cin>>n>>r;
		vector<vector<int>> v(n,vector<int> (n));

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>v[i][j];
		unordered_set<int> s;
		for(int i=0;i<n;i++)
			s.insert(v[r][i]);

		for(int i=0;i<n;i++)
		{
			if(i!=r)
			{
				bool flag=true;
				for(int j=0;j<n;j++)
				{
					if(s.find(v[i][j])==s.end())
					{	
						flag=false;
						break;
					}

				}
				if(flag==true)
					cout<<i<<endl;
			}
		}

	}
	return 0;
}