#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int prefix[n]={0};

	int temp;
	cin>>temp;
	prefix[0]=temp;
	for(int i=1;i<n;i++)
	{
		cin>>temp;
		prefix[i]=prefix[i-1]+temp;
	}

	for(int i=0;i<n;i++)
		cout<<prefix[i]<<" ";
	cout<<endl;

	int min_prefix_sum=prefix[0],max_sum=prefix[0];
	for(int i=0;i<n;i++)
	{
		if(prefix[i]<=min_prefix_sum)
			min_prefix_sum = prefix[i];

		if((prefix[i]-min_prefix_sum)>max_sum)
		{
			max_sum = prefix[i]-min_prefix_sum;
		}
	}

	cout<<max_sum<<endl;

	return 0;
}