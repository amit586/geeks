#include <bits/stdc++.h>
using namespace std;

int maxLoot(vector <int> v,int n)
{
	// if(i<0)
	// 	return sum;
	// else
	// 	return max(maxLoot(v,n,i-1,sum),maxLoot(v,n,i-2,sum+v[i]));


	int inc[n],exc[n];
	exc[0]=0;
	inc[0]=v[0];
	exc[1]=v[0];
	inc[1]=v[1];

	for(int i=2;i<n;i++)
	{
		exc[i] = max(inc[i-1],exc[i-1]);
		inc[i] = v[i]+exc[i-1];
	}

	// for(int i=0;i<n;i++)
	// 	cout<<inc[i]<<" ";
	// cout<<endl;
	// for(int i=0;i<n;i++)
	// 	cout<<exc[i]<<" ";
	// cout<<endl;

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
		vector <int> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];

		cout<<maxLoot(v,n)<<endl;
	}
	return 0;
}