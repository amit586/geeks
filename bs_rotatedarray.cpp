#include<bits/stdc++.h>
using namespace std;

int find_pivot(int arr[],int n)
{
	int mid,low=0,high=n-1;

	if(arr[low]<arr[high]) 
		return 0;
	
	while(low<high)
	{
		mid = low +(high-low)/2;
		//cout<<"mid : "<<mid<<endl;

		if(arr[mid]<arr[mid-1] && arr[mid]<arr[mid+1])
			return mid;
		else
		{
			if(arr[mid]>arr[low])
				low = mid;
			else
				high = mid-1;
		}
	}
}

int binary_search(int arr[],int low,int high,int key)
{
	int mid ;
	while(low <=high)
	{
		mid  = low + (high-low)/2;
		//cout<<"mid : "<<mid<<endl;
		if(arr[mid]==key)
			return mid;
		else
		{
			if(arr[mid]>key)
				high = mid-1;
			else 
				low = mid+1;
		}
	}
	return -1;
}


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
		
		int k;
		cin>>k;
		int pivot = find_pivot(arr,n),pos;
		//cout<<pivot<<endl;
		if(pivot==0)
			pos = binary_search(arr,0,n-1,k);
		else if(arr[n-1]>k)
			pos = binary_search(arr,pivot,n-1,k);
		else
			pos = binary_search(arr,0,pivot-1,k);
		cout<<pos<<endl;

		////int pivot = find_pivot(arr,n);
		//cout<<pivot<<endl;int pos = binary_search(arr,0,n-1,k);
		//cout<<"pos "<<pos<<endl;



	}
	return 0;
}