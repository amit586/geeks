#include <bits/stdc++.h>
using namespace std;



void reverse(int arr[],int start,int end)
{
    for(int i=start;i<=(end-start)/2;i++)
        swap(arr[i],arr[end-i]);
}

void rotate(int arr[],int k,int n)
{
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
    reverse(arr,0,n-1);
}


void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int n,k;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    cin>>k;
	    k = k%n;
	    rotate(arr,k,n);
	    print(arr,n);
	}
	return 0;
}