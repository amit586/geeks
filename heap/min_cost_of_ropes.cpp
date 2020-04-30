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
		priority_queue<int,vector<int>,greater<int>> pq;
		int temp;
		for(int i=0;i<n;i++)
			cin>>temp,pq.push(temp);
		long long cost=0;
		while(pq.size()>=2)
		{
			int l1=pq.top();
			pq.pop();
			int l2=pq.top();
			pq.pop();
			//cout<<l1+l2<<endl;
			cost+=(l1+l2);
			pq.push(l1+l2);
		}
		cout<<cost<<endl;
	}
	return 0;
}