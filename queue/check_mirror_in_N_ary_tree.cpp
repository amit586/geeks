#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define ll long long
#define ld long double
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second

using namespace std;

bool checkMirror(vector<int> *t1,vector<int> *t2,int root1,int root2)
{
	if(t1[root1].size()!=t2[root2].size())
		return false;

	stack<int> s;
	for(int i=0;i<t1[root1].size();i++)
		s.push(t1[root1][i]);

	for(int i=0;i<t2[root2].size();i++)
	{
		int temp = s.top();
		s.pop();
		if(!(t2[root2][i]==temp && checkMirror(t1,t2,temp,temp)))
			return false;
	}
	return true;
}

int main()
{
	fio
	int TC;
	cin>>TC;
	//TC=1;
	while(TC--)
	{
		int n,e;
		cin>>n>>e;
		vector<int> t1[n];
		vector<int> t2[n];
		int u,v;
		for(int i=0;i<e;i++)
		{
			cin>>u>>v;
			t1[u-1].push_back(v-1);
		}
		for(int i=0;i<e;i++)
		{
			cin>>u>>v;
			t2[u-1].push_back(v-1);
		}
		cout<<checkMirror(t1,t2,0,0)<<endl;
		
	}
	return 0;
}
