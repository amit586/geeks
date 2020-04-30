#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int64_t n,x;
		cin>>n>>x;
		vector<int64_t> v(n);
		unordered_set<int64_t> hash;
		bool present=false;
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			if(!present && x%v[i]==0 && hash.find(x/v[i])!=hash.end())
				present=true;
			hash.insert(v[i]);

		}
		cout<<(present?"Yes":"No")<<endl;

	}
	return 0;
}