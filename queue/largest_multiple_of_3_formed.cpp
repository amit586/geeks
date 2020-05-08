#include <bits/stdc++.h>
using namespace std;

void dequeueAll(int aux[],int &top,queue<int> &q0,queue<int> &q1,queue<int> &q2)
{
	while(!q0.empty())
		aux[top]=q0.front(),q0.pop(),top++;
	while(!q1.empty())
		aux[top]=q1.front(),q1.pop(),top++;
	while(!q2.empty())
		aux[top]=q2.front(),q2.pop(),top++;
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		queue<int> q0,q1,q2;
		sort(arr,arr+n);
		int sum=0;
		for(int i=0;i<n;i++)
		{
			sum+=arr[i];
			if(arr[i]%3==0)
				q0.push(arr[i]);
			else if(arr[i]%3==1)
				q1.push(arr[i]);
			else 
				q2.push(arr[i]);
		}
		int aux[n];
		int top=0;
		bool flag=true;
		if(sum%3==1)
		{
			if(!q1.empty())
				q1.pop();
			else if(q1.empty() && q2.size()>=2)
				q2.pop(),q2.pop();
			else
				flag=false;
		}

		if(sum%3==2)
		{
			if(!q2.empty())
				q2.pop();
			else if(q2.empty() && q1.size()>=2)
				q1.pop(),q1.pop();
			else 
				flag=false;
		}

		if(flag)
		{
			dequeueAll(aux,top,q0,q1,q2);
			sort(aux,aux+top,greater<int>());
			for(int i=0;i<top;i++)
				cout<<aux[i];
		}
		else
			cout<<-1<<endl;


	}
	return 0;
}