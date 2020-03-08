#include <bits/stdc++.h>
using namespace std;

int count(int n)
{
	int a[n+1]={0};
	int b[n+1]={0};

	a[0]=1;
	a[1]=0;
	b[0]=0;
	b[1]=1;

	for(int i=2;i<=n;i++)
	{
		a[i]=a[i-2] + 2* b[i-1];
		b[i]=a[i-1] + b[i-2];
	}
	return a[n];
}


int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		
		cout<<count(n)<<endl;
	}
	return 0;
}