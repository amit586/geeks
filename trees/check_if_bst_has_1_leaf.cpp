#include <bits/stdc++.h>
using namespace std;

bool solve(int pre[],int N)
{
	int mx=INT_MAX,mn = INT_MIN;
	for(int i=0;i<N;i++)
	{
		if(pre[i]>= mx or pre[i]<=mn)
			return false;
		if(i<N-1 and pre[i+1]>pre[i])
			mn = pre[i];
		else
			mx=pre[i];
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int pre[n];
	for(int i=0;i<n;i++)
		cin>>pre[i];

	cout<<solve(pre,n)<<endl;
	return 0;
}