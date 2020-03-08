#include <iostream>
using namespace std;

int find_pivot(int arr[],int s,int e)
{
   if(s>e) return -1;
}


int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	   int pivot = find_pivot(arr,0,n-1);
	   cout<<pivot<<endl;
	    
	}
	return 0;
}