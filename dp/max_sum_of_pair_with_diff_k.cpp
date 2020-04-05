#include<bits/stdc++.h>
using namespace std;

int maxSum(vector <int> &v,int n,int k)
{
		
}

int main(int argc, char const *argv[])
{
	int tc;
	while(tc--)
	{
		int n,k;
		cin>>n>>k;
		vector<int> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		sort(v.begin(),v.end());
		cout<<maxSum(v,n,k)<<end;
	}
	return 0;
}