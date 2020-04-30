#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> &v1,vector<int>&v2)
{
	vector<int> merged(v1.size()+v2.size());
	int i=0,j=0,k=0,n1=v1.size(),n2=v2.size();

	while(i<n1 && j<n2)
		if(v1[i]<v2[j])
			merged[k]=v1[i],k++,i++;
		else 
			merged[k]=v2[j],k++,j++;	
	while(i<n1)
		merged[k]=v1[i],i++,k++;
	while(j<n2)
		merged[k]=v2[j],j++,k++;
	return merged;
}

vector<int> mergeKsorted(vector<vector<int>>&v,int start,int end)
{
	if(start==end)
		return v[start];
	if(end-start==1)
		return merge(v[start],v[end]);
	int partition=(start+end)/2;
	vector<int> v1 = mergeKsorted(v,start,partition);
	vector<int> v2 = mergeKsorted(v,partition+1,end);
	vector<int> merged = merge(v1,v2);
	return merged;
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,k;
		cin>>k;
		n=k;
		vector<vector<int>> v(k,vector<int> (n));
		for(int i=0;i<k;i++)
			for(int j=0;j<n;j++)
				cin>>v[i][j];
		vector<int> merged=mergeKsorted(v,0,k-1);
		for(int i= 0;i<merged.size();i++)
			cout<<merged[i]<<" ";
		cout<<endl;
	}
	return 0;
}