#include <bits/stdc++.h>
using namespace std;

// int maxSumLen(const vector<int> &v,int n,int sum)
// {
// 	if(n<0)
// 		return 0;
// 	else
// 	{
// 		if(sum>sum+v[n])
// 			return maxSumLen(v,n-1,0);
// 		else
// 			return 1+maxSumLen(v,n-1,sum+v[n]);
// 	}

// }

int sum(vector<int> &v,int j,int i)
{
	int s=0;
	for(int k=j;k<i;k++)
		s+=v[k];
	return s;
}

int maxSumLen(vector<int> &v,int n)
{
	int mLen=1;
	int golbal_sum=INT_MIN;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n-i;j++)
		{
			int s;
			if(j==0)
				s=sum(v,j,j+i);
			else
				s=s +v[j+i-1]-v[j-1];
			
			if(s>=golbal_sum)
			{
				golbal_sum=s;
				mLen=i;
			}
		}
	}
	return mLen;
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

		cout<<maxSumLen(v,n)<<endl;
	}
	return 0;
}