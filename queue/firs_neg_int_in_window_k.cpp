#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,k;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cin>>k;
		queue<int> q;
		for(int i=0;i<k;i++)
			if(arr[i]<0)
				q.push(i);

		for(int i=k;i<n;i++)
		{
			q.empty()?cout<<0<<" ":cout<<arr[q.front()]<<" ";
			while(!q.empty() && q.front()<=i-k)
				q.pop();
			if(arr[i]<0)
				q.push(i);
		}
		q.empty()?cout<<0<<endl:cout<<arr[q.front()]<<endl;

	}
	return 0;
}