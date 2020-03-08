#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int arr[n][2];
		for(int i=0;i<n;i++)
			cin>>arr[i][0];
		for(int i=0;i<n;i++)
			cin>>arr[i][1];

		for(int i=0;i<n;i++)
		{
			if(arr10, 11, 12];
        index[] = [1, 0, 2];[i][1]!=i)
			{
				int temp[2]={arr[i][0],arr[i][1]};
				arr[i][0] = arr[temp[1]][0];
				arr[i][1] = arr[temp[1]][1];
				arr[temp[1]][0]=temp[0];
				arr[temp[1]][1]=temp[1];
			}
		}
		for(int i=0;i<n;i++)
			cout<<arr[i][0]<<" ";
		cout<<endl;


	}
	return 0;
}