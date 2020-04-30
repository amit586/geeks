#include <bits/stdc++.h>
using namespace std;

int query(int *st,int si,int ss,int se,int qs,int qe)
{
	if(ss>qe || se<qs)
		return 0;
	if(ss>=qs && qe>=se)
		return st[si];
	int mid=(ss+se)/2;
	return query(st,2*si+1,ss,mid,qs,qe)+query(st,2*si+2,mid+1,se,qs,qe);

}

int buildStUntil(vector<int> &v,int ss,int se,int *st,int si)
{
	if(ss==se)
	{
		if(v[ss]%5==0)
			st[si]=1;
		else
			st[si]=0;
		return st[si];
	}
	int mid = (ss+se)/2;
	st[si]=buildStUntil(v,ss,mid,st,2*si+1)+buildStUntil(v,mid+1,se,st,2*si+2);
	return st[si];
}

int *buildSt(vector<int> &v,int n)
{
	int mx_sz = 2*pow(2,(int)ceil(log2(n)))-1;
	int *st = new int[mx_sz];
	buildStUntil(v,0,n-1,st,0);
	return st;
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,q;
		cin>>n>>q;
		vector<int> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		int *st = buildSt(v,n);
		while(q--)
		{
			int l,r;
			cin>>l>>r;
			cout<<query(st,0,0,n-1,l-1,r-1)<<" ";
		}
		cout<<endl;
	}
	return 0;
}