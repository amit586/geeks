#include <bits/stdc++.h>
using namespace std;

bool divisibleSum(vector <int> &v,int n,int m,int i,int sum)
{
	//cout<<sum<<endl;
	if(sum && sum%m==0)
		//cout<<"sum "<<sum<<" m "<<m<<endl;
		return true;
	if(i==n)
		return false;
	return divisibleSum(v,n,m,i+1,sum)||divisibleSum(v,n,m,i+1,sum+v[i]);

}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,m;
		cin>>n>>m;
		vector <int> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		cout<<divisibleSum(v,n,m,0,0)<<endl;
	}
	return 0;
}