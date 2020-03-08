#include <bits/stdc++.h>
using namespace std;

int cut(int len,std::map<int,int> &m,int dp[])
{
	if(len==0)
	{
		return 0;
	}
	else if(len<0)
	{
		return INT_MIN;
	}
	else if(dp[len]!=0)
		return dp[len];
	else
	{
		int mx = INT_MIN;
		for(auto it:m)
		{
			mx = max(mx,it.second + cut(len-it.first,m,dp));
		}
		dp[len]=mx;
		return dp[len];
	}

}


int main(int argc, char const *argv[])
{
	int n;
	std::map<int, int> m;
	cin>>n;
	int len,price;
	for(int i=0;i<n;i++)
	{
		cin>>len>>price;
		m[len]=price;
	}
	cin>>len;
	int dp[len+1]={0};
	price = cut(len,m,dp);
	cout<<price<<endl; 

	return 0;
}