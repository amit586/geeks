#include <bits/stdc++.h>
using namespace std;

int diff(tuple<int,int,int> t1)
{
	return get<1>(t1)-get<0>(t1);
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		unordered_map <int,tuple<int,int,int>> m;
		vector<int> v(n);
		int mx_fr =INT_MIN;
		int mx_fr_ele = -1;
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			if(m.find(v[i])==m.end())
				m[v[i]]=make_tuple(i,-1,1);
			else
			{
				get<1>(m[v[i]])=i;
				get<2>(m[v[i]])++;
			}
			if(mx_fr< get<2>(m[v[i]]) || (mx_fr == get<2>(m[v[i]]) && (diff(m[v[i]]) < diff(m[mx_fr_ele]))) )
				mx_fr = get<2>(m[v[i]]),mx_fr_ele=v[i];
		}
		
		if(get<0>(m[mx_fr_ele])<get<1>(m[mx_fr_ele]))
		{
			for(int i=get<0>(m[mx_fr_ele]);i<=get<1>(m[mx_fr_ele]);i++)
				cout<<v[i]<<" ";
			cout<<endl;
		}
		else
			cout<<v[0]<<endl;
	}
	return 0;
}