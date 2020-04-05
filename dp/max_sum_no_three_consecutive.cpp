#include <bits/stdc++.h>
using namespace std;

int maxsum(const vector<int> &v,int n)
{
	int exc[n+1]={0};
	int inc[n+1]={0};
	exc[0]=0;
	inc[0]=v[0];
	inc[1]=inc[0]+v[1];
	exc[1]=v[0];
	exc[2]=v[0]+v[1];
	inc[2]=max(v[0]+v[2],v[1]+v[2]);
	cout<<endl;
	for(int i=3;i<n;i++)
	{
		exc[i]=max(inc[i-1],exc[i-1]);

		if(  ( (exc[i-3]+v[i-2] +v[i-1]) == inc[i-1] )  )
			inc[i]=v[i]+max(exc[i-1],exc[i-2]+v[i-1]);
		else
			inc[i]=v[i]+max(inc[i-1],exc[i-1]);
	}
	cout<<"inc:\t";
	for(int i=0;i<n;i++)
		cout<<inc[i]<<"\t";
	cout<<endl;
	cout<<"exc:\t";
	for(int i=0;i<n;i++)
		cout<<exc[i]<<"\t";
	cout<<endl;
	return max(inc[n-1],exc[n-1]);
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
		cout<<maxsum(v,n)<<endl;
	}
	return 0;
}