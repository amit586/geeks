#include <iostream>
#include<climits>
using namespace std;

void print3largest(int arr[],int n)
{
	int i=0,first,second,third;
	first=second=third=INT_MIN;

	for(int i=0;i<n;i++)
	{
		if(arr[i]>first)
		{
			third = second;
			second = first;
			first = arr[i];
		}

		else if(arr[i]>second)
		{
			third = second;
			second = arr[i];
		}
		else if(arr[i]>third)
			third = arr[i];
	}
	cout<<third<<endl;
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	print3largest(arr,n);

	return 0;
}