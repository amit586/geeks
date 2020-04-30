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
		unordered_map<int,int> hash;
		for(int i=0;i<n;i++)
			cin>>v[i],hash[v[i]]+=1;
		stack<int> s;
		vector<int> ans(n,-1);
		s.push(n-1);
		for(int i=n-2;i>=0;i--)
		{
			while(!s.empty() && hash[v[s.top()]]<= hash[v[i]])
				s.pop();
			ans[i] = s.empty()?-1:v[s.top()];
			s.push(i);
		}
		for(int i=0;i<n;i++)
			cout<<ans[i]<<" ";
		cout<<endl;		
	}
	return 0;
}