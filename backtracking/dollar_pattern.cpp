#include <bits/stdc++.h>
using namespace std;

int count(int n,int h)
{
	if(n==0)
		return 1;
	else if(n<0)
		return 0;
	else if(h==0 && n!=0)
		return 0;
	else
	{
		int ans =0;
		for(int i=1;i<=h;i++)
		{
			ans+=count(n-i,i);
		}
		return ans;
	}
}


int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		cout<<count(n,n)<<endl;
	}
	return 0;
}