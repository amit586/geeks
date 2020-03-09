#include<bits/stdc++.h>
using namespace std;
pair<int,int> len(int n)
{
	int l=0,s=0;
	while(n>0)
	{
		l++;
		s+=n%10;
		n=n/10;
	}
	return make_pair(l,s);
}
int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		long long n;
		cin>>n;
		int l = INT_MAX;
		pair <int,int> p ;
		while(l>1)
		{
			p = len(n);
			n = p.second;
			l = p.first;
		}
		cout<<p.second<<endl;
		
	}
}
