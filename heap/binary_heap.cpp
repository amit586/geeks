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
		make_heap(v.begin(),v.end());
		cout<<v.front()<<endl;
		v.push_back(100);
		push_heap(v.begin(),v.end());
		cout<<v.front()<<endl;
		pop_head(v.begin(),v.end());
		v.pop_back();
	}
	return 0;
}