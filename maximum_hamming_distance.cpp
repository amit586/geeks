#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			/* code */cin>>arr[i];
		}
		int copy[2*n];
		for(int i=0;i<2*n;i++)
		{
			copy[i]=arr[i%n];
		}

		int max_hamming = 0;
		for(int i=0;i<n;i++)
		{
			int start = i,hamming=0;
			for(int j=0;j<n;j++)
			{
				if(arr[j]!=copy[i+j])
					hamming++;
			}
			if(hamming>max_hamming)
				max_hamming = hamming;
		}
		cout<<max_hamming<<endl;




	}
	return 0;
}