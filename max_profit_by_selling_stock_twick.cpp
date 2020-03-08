#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int profit[n]={0};

	int max_price=arr[n-1];
	for(int i=n-1;i<=0;i--)
	{
		max_price = max(arr[i],max_price);
		profit[i]=max(profit[i+1],max_price-arr[i]);
	}

	int min_price=arr[0];
	for(int i=1;i<n;i++)
	{
		min_price  = min(arr[i],min_price);
		profit[i]=max(profit[i]+arr[i]-min_price,profit[i-1]);
	}
	cout<<profit[n-1];
	return 0;
}