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
		vector<int > v(n);
		priority_queue<int> pq;
		for(int i=0;i<n;i++)	cin>>v[i];

		int local_mx=v[0];
		int global_mx = v[0];
		for(int i=1;i<n;i++)
		{
			local_mx = max(local_mx,local_mx+v[i]);
			if(local_mx>global_mx)
				global_mx=local_mx,pq.push(global_mx);
		}
		k--;
		while(k--)
			pq.pop();
		cout<<pq.top()<<endl;
	}
	return 0;
}