// C++ program for rearrange an 
// array such that arr[i] = i. 
#include<stdio.h> 

int main() 
{ 
	int arr[] = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	for (int i = 0; i < n;) 
	{ 
		if (arr[i] >= 0 && arr[i] != i) 
		arr[arr[i]] = (arr[arr[i]] + arr[i]) - (arr[i] = arr[arr[i]]); 
		else
			i++; 
	} 
	for(int i = 0; i < n; i++) 
		printf("%d ",arr[i]); 
		return 0; 
} 

// This Code is Contributed by Adarsh_Verma 
