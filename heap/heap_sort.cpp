#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &v,int n,int i)
{
	int mx=i;
	int l=2*i+1;
	int r=2*i+2;

	if(l<n && v[mx]<v[l])
		mx=l;

	if(r<n && v[mx]<v[r])
		mx=r;
	if(mx!=i)
		swap(v[i],v[mx]),heapify(v,n,mx);
}


void heapsort(vector<int> &v,int n)
{
	for(int i=n/2-1;i>=0;i--)
		heapify(v,n,i);

	 for(int i=n-1;i>0;i--)
	 	swap(v[i],v[0]),heapify(v,i,0);
}


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
		heapsort(v,n);
		for(int i=0;i<n;i++)
			cout<<v[i]<<" ";
		cout<<endl;
	}
	return 0;
}