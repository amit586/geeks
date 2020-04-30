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

		vector<int> ans(n);
		priority_queue<int> pq;
		
		for(int i=0;i<n;i++)
			pq.push(v[i]);

		for(int i=0;i<n;i++)
		{
			int d = pq.top();
			pq.pop();
			if(d!=v[i] || i==n-1)
				ans[i]=d;
			else
				ans[i]=pq.top(),pq.pop(),pq.push(d);
		}

		if(ans[n-1]==v[n-1])
		{
			ans[n-1]=ans[n-2];ans[n-2]=v[n-1];
		}

		for(int i=0;i<n;i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}