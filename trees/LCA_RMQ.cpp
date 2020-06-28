#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class tour
{
public:
	vector<int> *T;
	vector<vector<int>> st;
	vector<int> et,eh,fo,h,lg;
	int n,ptr;
	tour(int N,vector<int> *t)
	{
		T=t;
		n=N;
		ptr=0;
		h = vector<int> (n,0);
		fo = vector<int> (n,-1);
	}	


	void eulerTour(int root,int parent,int height)
	{
		et.pb(root);
		eh.pb(height);
		h[root]=height;
		if(fo[root]==-1)
			fo[root]=ptr;
		ptr++;
		for(auto it:T[root])
			if(it!=parent)
				eulerTour(it,root,height+1),et.pb(root),eh.pb(height),ptr++;
	}

	void buildST()
	{
		int N = ptr;
		lg = vector<int> (N+1,0);
		for(int i=2;i<=N;i++)
			lg[i]=lg[i>>1]+1;

		st = vector<vector<int>> (N+1,vector<int> (20));
		for(int i=0;i<N;i++)
			st[i][0]=i;

		for(int j=1;j<=lg[N]+1;j++)
			for(int i=0;i+(1<<j)<=N;i++)
				st[i][j] = eh[st[i][j-1]]<eh[st[i+(1<<(j-1))][j-1]]?st[i][j-1]:st[i+(1<<(j-1))][j-1];
	}

	int LCA(int u,int v)
	{
		int L = fo[u],R = fo[v];
		if(R<L)
			swap(L,R);
		int j = lg[R-L+1];
		return (eh[st[L][j]]<eh[st[R-(1<<j)+1][j]])?et[st[L][j]]:et[st[R-(1<<j)+1][j]];
	}
};

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,q;
		cin>>n>>q;
		vector<int> T[n];
		int u,v;
		for(int i=0;i<n-1;i++)
			cin>>u>>v,T[u-1].pb(v-1),T[v-1].pb(u-1);

		tour t(n,T);
		t.eulerTour(0,-1,0);
		t.buildST();
		while(q--)
		{
			cin>>u>>v;
			cout<<t.LCA(u-1,v-1)+1<<endl;
		}

	}
	return 0;
}