#include<iostream>
#define p 1000000007
#define ll long long 
using namespace std;

int main()
{
	int n;
	cin>>n;
	ll prev=1,curr=1,next;
	for(int i=2;i<=n;i++)
	{
		next = 2*curr + prev;
		next%=p;
		prev = curr;
		curr = next;
		cout<<next<<" ";
	}
	cout<<endl;
	return 0;
}
