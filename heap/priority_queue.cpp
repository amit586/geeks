#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>> n;
	vector<int > v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	priority_queue<int,vector<int>> pq(v.begin(),v.end());
	return 0;
}