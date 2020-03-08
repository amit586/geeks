#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int local_sum=0,global_sum;
		for(int i=0;i<k;i++)
			local_sum+=arr[i];
		global_sum=local_sum;
		int end_index = k-1;
		for (int i = k; i < n; ++i)
		{
			local_sum+=arr[i];
			local_sum-=arr[i-k];
			if(local_sum<global_sum)
			{
				global_sum=local_sum;
				end_index=i;
			}
		}
		cout<<(end_index+1)-(k-1)<<" "<<end_index+1<<endl;

	}
	return 0;
}