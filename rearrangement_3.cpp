#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n,[](int a,int b)->bool
			{
				if((a<0 && b>0) || (a<0 && b==0) || (a==b&& b>0)) return true;
				return false;
			});
		for(int i=0;i<n;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}

	return 0;
}