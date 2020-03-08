#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)	
		cin>>arr[i];

	/////////////finding indeces ///////////

	int global_max=arr[0],local_max=arr[0];
	int p_start=0,p_end = 0,start=0;

	for (int i = 1; i < n; ++i)
	{
		if(arr[i]>local_max+arr[i])
		{
			start = i;
			local_max =arr[i];
		}
		else
			local_max+=arr[i];

		if(local_max>global_max)
		{
			global_max = local_max;
			p_start = start;
			p_end = i;
		}
	}
	cout<<p_start<<" "<<p_end<<endl;
	return 0;
}