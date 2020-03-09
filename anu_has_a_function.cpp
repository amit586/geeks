#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	long long arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	int max=0,msb=0,index=0;
	long long temp;
	for(int i=0;i<n;i++)
	{	temp=arr[i];
		msb=0;
		while(temp>0)
		{
			temp=temp/2;
			msb++;
		}
		if(max<msb)
		{
			max = msb;
			index=i;
		}
	}
	//cout<<"index "<<index<<" max "<<max<<endl;
	swap(arr[0],arr[index]);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	
	return 0;
}
