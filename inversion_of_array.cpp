#include <bits/stdc++.h>
#define ll long long
using namespace std;

int merge(vector<ll> &v,vector<ll> &temp,int low,int mid,int high )
{
	int inv = 0;
	if(low<high)
	{	
		int k = low;
		int i = low;
		int j = mid;
		while(i<=mid-1 and j<=high)
		{
			if(v[i]<v[j])
				temp[k++]=v[i++];
			else
			{
				temp[k++]=v[j++];
				inv +=mid-i;
			}
		}

		while(i<=mid-1)
			temp[k++]=v[i++];
		while(j<=high)
			temp[k++]=v[j++];

		for(int i=low;i<=high;i++)
			v[i] = temp[i];

	}
	return inv;
}

int merge_sort(vector<ll> &v,vector<ll> &temp,int low,int high)
{
	int inv = 0;
	if(low<high)
	{
		int mid = (low+high)/2;

		inv+=merge_sort(v,temp,low,mid);
		inv+=merge_sort(v,temp,mid+1,high);
		inv+=merge(v,temp,low,mid+1,high);
	}
	return inv;
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		vector<ll> v(n),temp(n);
		for(int i=0;i<n;i++)	cin>>v[i];

		int inv = merge_sort(v,temp,0,n-1);
		cout<<inv<<endl;
	}
	return 0;
}