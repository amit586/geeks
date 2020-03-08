#include<bits/stdc++.h>
using namespace std;
//// rotation using  reversal

void reverse(int arr[],int start,int end)
{
	for(int i=start;i<=(end-start)/2;i++)
	{
		swap(arr[i],arr[end-i]);
	}
}

void rotate(int arr[],int k,int n)
{
	reverse(arr,0,k-1);
	reverse(arr,k,n-1);
	reverse(arr,0,n-1);

}


///// rotation using jumps
void leftRotate(int arr[],int k,int n)
{
	int gcd= __gcd(n,k);
	for(int i=0;i<gcd;i++)
	{
		int temp = arr[i];
		int j=i,l;
		while(1)
		{
			l = (j+k)%n;
			if(l==i) break;
			arr[j] = arr[l];
			j= l;
		}
		arr[j]=temp;
	}	
}



void printArray(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
} 


int main() 
{ 
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    // Function calling 
    //leftRotate(arr, 2, n); 
    rotate(arr,2,n);
    printArray(arr, n); 
  
    return 0; 
} 