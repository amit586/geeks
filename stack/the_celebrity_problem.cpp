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
		vector<vector<int>> rel(n,vector<int>(n));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>rel[i][j];
		stack<int> suspect;
		for(int i=0;i<n;i++)
			suspect.push(i);
		while(suspect.size()>1)
		{
			int x = suspect.top();
			suspect.pop();
			int y = suspect.top();
			suspect.pop();
			if(rel[x][y]==1 && rel[y][x]==0)
				suspect.push(y);
			else if(rel[x][y]==0 && rel[y][x]==1)
				suspect.push(x);				
		}
		if(suspect.empty())
		{
			cout<<-1<<endl;
			continue;
		}
		int ans = suspect.top();
		for(int i=0;i<n;i++)
			if(i!=suspect.top() && rel[i][suspect.top()]!=1)
			{
				ans = -1;
				break;
			}		
		cout<<ans<<endl;
	}
	return 0;
}