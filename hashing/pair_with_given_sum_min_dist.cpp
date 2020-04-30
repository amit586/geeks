#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &v,int n,int k)
{
	unordered_set<int> hash;
	int min_dist = INT_MAX;
	for(int i = 0;i<n;i++)
	{
		if(hash.find(k-v[i])!=hash.end())
			min_dist = min(min_dist,n-i);
		hash.insert(v[i]);
	}
	return min_dist;
}
 
int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,k;
		cin>>n>>k;
		vector<int> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		cout<<solve(v,n,k)<<endl;
	}
	return 0;
}