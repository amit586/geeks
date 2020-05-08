#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,k;
		cin>>n>>k;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		deque<int> Qi(k);
		int i=0;
		for(;i<k;i++)
		{
			while(!Qi.empty() && arr[Qi.back()]<=arr[i])
				Qi.pop_back();
			Qi.push_back(i);
		}

		for(;i<n;i++)
		{
			cout<<arr[Qi.front()]<<" ";
			while(!Qi.empty() && Qi.front()<=i-k)
				Qi.pop_front();

			while(!Qi.empty() && arr[Qi.back()]<=arr[i])
				Qi.pop_back();
			Qi.push_back(i);
		}
		
		cout<<arr[Qi.front()]<<" ";
		cout<<endl;
	}
	return 0;
}