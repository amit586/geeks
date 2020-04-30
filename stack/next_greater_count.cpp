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
		vector<int> nextG(n,0);
		stack<int> s;
		s.push(n-1);
		for(int i=n-2;i>=0;i--)
		{
			while(!s.empty() && v[s.top()]<=v[i])
				s.pop();
			nextG[i] = s.empty()?0:1+nextG[s.top()];
			s.push(i);
		}

		for(int i=0;i<n;i++)
			cout<<nextG[i]<<" ";
		cout<<endl;
	}
	return 0;
}