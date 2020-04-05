#include <bits/stdc++.h>
using namespace std;

int maxLen(vector <int> &v,int n)
{
	int max_local=0,max_global=0;
	int len_local=0,len_global;
	for(int i=0;i<n;i++)
	{
		max_local = max_local+v[i];
		len_local++;
		
		if(max_local<0)
		{
			max_local=0;
			len_local=0;
		}
		if(max_global<=max_local)
		{
			max_global=max_local;
			len_global=len_local;
		}
	}
	return len_global;
}

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

		cout<<maxLen(v,n)<<endl;
	}
	return 0;
}