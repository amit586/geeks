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
		vector<char> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		vector<int> freq(26,0);
		queue<char> q;
		for(int i=0;i<n;i++)
		{
			freq[v[i]-'a']++;
			while(!q.empty() && freq[q.front()-'a']>1)
				q.pop();
			if(freq[v[i]-'a']==1)
				q.push(v[i]);
			q.empty()?cout<<-1<<" ":cout<<q.front()<<" ";
		}
		cout<<endl;
	}
	return 0;
}