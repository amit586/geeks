#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> v(n);
		for(long long i=0;i<n;i++)
			cin>>v[i];
		stack <long long> s;
		vector<long long> nextG(n,-1);
		nextG[n-1]=-1;
		s.push(n-1);
		for(long long i=n-2;i>=0;i--)
		{
			while(!s.empty() && v[s.top()]<= v[i])
				s.pop();
			nextG[i]=s.empty()?-1:v[s.top()];
			s.push(i);
		}
		for(long long i=0;i<n;i++)
			cout<<nextG[i]<<" ";
		cout<<endl;
	}
	return 0;
}