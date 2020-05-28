#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define ll long long
#define ld long double
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second

using namespace std;

int main()
{
	fio
	int TC;
	cin>>TC;
	//TC=1;
	while(TC--)
	{
		int V,E;
		cin>>V>>E;
		vector<int> g1[V],g2[V];
		int u,v;
		for(int i=0;i<E;i++)
			cin>>u>>v,g1[u].push_back(v);
		for(int i=0;i<E;i++)
			cin>>u>>v,g2[u].push_back(v);
		bool ans=true;
		for(int i=0;i<V;i++)
		{
			for(int j=0;j<g1[i].size();j++)
				if(g1[i][j]!=g2[i][g2[i].size()-1-j])
					{ans = false;break;}
			if(ans==false)
				break;
		}
		cout<<ans<<endl;		
	}
	return 0;
}
