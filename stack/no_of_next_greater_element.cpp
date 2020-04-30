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
		vector<int> ans(n,0);
		stack<int> s;
		s.push(n-1);
		for(int i=n-2;i>=0;i--)
		{
			while(!s.empty() && v[s.top()]<=v[i])
				s.pop();
			if(!s.empty())
				for(int j=s.top();j<n;j++)
					if(v[j]>v[i])
						ans[i]++;
			s.push(i);
		}

		for(int i=0;i<n;i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}