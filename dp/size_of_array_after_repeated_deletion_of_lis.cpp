#include <bits/stdc++.h>
using namespace std;

vector<int> LIS(vector<int> &v,int n)
{
	vector<vector<int>> dp(n);
	for(int i=0;i<n;i++)
	{
		int mx_index=-1;
		int mx_size=0;
		for(int j=0;j<i;j++)
		{
			if(v[i]>v[j] && dp[j].size()>=mx_size)
			{
				mx_size=dp[j].size();
				mx_index=j;
			}
		}
		dp[i].push_back(i);
		if(mx_index!=-1)
		{
			//dp[i]=dp[mx_index];
		dp[i].insert(dp[i].end(),dp[mx_index].begin(),dp[mx_index].end());
		}
		
		
	}
	int ans_max=0;
	int ans_index=-1;
	for(int i=0;i<n;i++)
	{
		if(dp[i].size()>=ans_max)
		{
			ans_max=dp[i].size();
			ans_index=i;
		}
	}
	return dp[ans_index];
}


void sizeOfArray(vector<int> &v,int n)
{
	vector<int> arr=v;
	
	while(arr.size()>0)
	{
		vector <int> lis = LIS(arr,arr.size());
		// for(int i=0;i<lis.size();i++)
		// 	cout<<lis[i]<<" ";
		// cout<<endl;
		if(lis.size()<2)
			break;
		
		for(int i=0;i<lis.size();i++)
			arr.erase(arr.begin()+lis[i]); 
	}
	if(arr.size()>0)
	{
		for(int i=0;i<arr.size();i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
	else
		cout<<-1<<endl;
	//return (arr.size()>0?arr.size():-1);
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

		sizeOfArray(v,n);
	}
	return 0;
}