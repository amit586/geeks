#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		string s;
		int k;
		cin>>s>>k;
		int n = s.size();
		vector<int>freq(26,0);
		for(int i=0;i<n;i++)
			freq[s[i]-'a']++;
		priority_queue<int,vector<int>> pq(freq.begin(),freq.end());
		while(!pq.empty() && k>0)
		{
			int top = pq.top();
			pq.pop();
			k--;
			top--;
			pq.push(top);
		}
		int val=0;
		while(!pq.empty())
		{
			val +=pq.top()*pq.top();
			pq.pop();
		}
		cout<<val<<endl;


	}
	return 0;
}