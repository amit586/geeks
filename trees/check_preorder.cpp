#include <bits/stdc++.h>
#define INF 1000000
using namespace std;

// bool check(int pre[],int n)
// {
// 	stack<int> s;
// 	int nextg[n],minima[n];
// 	nextg[n-1]=INF,minima[n-1]=pre[n-1];
// 	s.push(n-1);
// 	for(int i=n-2;i>=0;i--)
// 	{
// 		while(!s.empty() and pre[s.top()]<pre[i])
// 			s.pop();
// 		nextg[i] = s.empty()?INF:s.top();
// 		minima[i] = min(pre[i],minima[i+1]);
// 		s.push(i);
// 	}
// 	for(int i=0;i<n;i++)
// 		if(nextg[i]!=INF and minima[nextg[i]]<pre[i])
// 			return false;
// 	return true;
// }

bool check(int pre[],int n)
{
	stack<int> s;
	int root = -INF;
	for(int i=0;i<n;i++)
	{
		if(root>pre[i])
			return false;
		while(!s.empty() and pre[i]>s.top())
			root = s.top(),s.pop();
		s.push(pre[i]);
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int pre[n];
	for(int i=0;i<n;i++)	cin>>pre[i];
	cout<<check(pre,n)<<endl;
	return 0;
}