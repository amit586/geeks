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
		for (int i = 0; i < n; ++i)
		{
			/* code */
			cin>>v[i];
		}
		int ans;
		make_heap(v.begin(),v.end());
		for(int i=0;i<k;i++)
		{
			ans=v.front();
			pop_heap(v.begin(),v.end()-i);
		}
		cout<<ans<<endl;
	}
	return 0;
}