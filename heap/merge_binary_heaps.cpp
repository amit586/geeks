#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &v,int i,int n)
{
	int mx=i;
	int l=2*i+1,r=2*i+2;
	if(l<n && v[l]>v[mx])
		mx=l;
	if(r<n && v[r]>v[mx])
		mx=r;
	if(mx!=i)
		swap(v[mx],v[i]),heapify(v,mx,n);
}

void build_heap(vector<int> &v,int n)
{
	for(int i=n/2-1;i>=0;i--)
		heapify(v,i,n);
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n1,n2;
		cin>>n1>>n2;
		vector<int> v1(n1),v2(n2);
		vector<int> hp(n1+n2);
		int k=0;
		for(int i=0;i<n1;i++)	cin>>v1[i],hp[k]=v1[i],k++;
		for(int i=0;i<n2;i++)	cin>>v2[i],hp[k]=v2[i],k++;
		build_heap(hp,n1+n2);
		for(int i=0;i<n1+n2;i++)
			cout<<hp[i]<<" ";
		cout<<endl;


	}
	return 0;
}