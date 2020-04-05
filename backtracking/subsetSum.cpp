#include <bits/stdc++.h>
using namespace std;

int countSubsets(vector <int> v,int sum,int i,int n)
{
	if(i>=n)
		return 0;
	else if(sum==0)
		return 1;
	else if(sum<0)
		return 0;
	else
		return countSubsets(v,sum-v[i],i+1,n)+countSubsets(v,sum,i+1,n);
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,k;
		cin>>n>>k;
		vector <int> v(n,0);
		for(int i=0;i<n;i++)
			cin>>v[i];

		int total = countSubsets(v,k,0,n);
		cout<<total<<endl;
	}
	return 0;
}