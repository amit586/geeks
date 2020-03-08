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
		for(int i=0;i<n;i++)
		{  	int temp;
			cin>>temp;
			arr[i]=temp+1;
		}
		for(int i=0;i<n;i++)
		{	
			if(arr[i]>0)
			{
				int j,temp,i1=i;
				while(arr[i1]>0)
				{
					j=arr[i1]-1;
					temp = arr[j]-1;
					arr[j]=-i1;
					i1=temp;
				}
			}
		}
		for(int i=0;i<n;i++)
			cout<<-arr[i]-1<<" ";
		cout<<endl;
	}
	return 0;
}