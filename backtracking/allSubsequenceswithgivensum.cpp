#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &v)
{
	for(auto it=v.begin();it!=v.end();++it)
		cout<<*it<<" ";
	cout<<endl;
}

void printSubsequence(vector <int> &v, int sum,int i,vector <int> &sol,int n)
{	//cout<<"i : "<<i<<endl;
	if(i>n)
		return ;
	else if(sum<0)
		return ;
	else if(sum==0)
		printVector(sol);
	else
	{
		printSubsequence(v,sum,i+1,sol,n);
		sol.push_back(v[i]);
		printSubsequence(v,sum-v[i],i+1,sol,n);
		sol.pop_back();
	}
}

int main()
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,k;
		cin>>n>>k;
		vector <int> v(n);
		for(int i=0;i<n;i++)
			cin>>v[i];
		vector <int> sol;
		printSubsequence(v,k,0,sol,n);
	}
	return 0;
}