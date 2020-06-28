#include <bits/stdc++.h>
#define INF 100000
#define s second
#define f first
using namespace std;

bool check(int lo[],int n)
{
	queue<pair<int,int>> q;
	q.push({-INF,INF});
	int i=0;
	while(i<n)
	{
		pair<int,int> range = q.front(),l,r;
		while(!q.empty() and (lo[i]>range.s or lo[i]<range.f))
			q.pop(),range = q.front();
		if(q.empty() )
			return false;
		l = {range.f,lo[i]};
		r = {lo[i],range.s};
		q.push(l);
		q.push(r);
		//cout<<range.f<<" "<<range.s<<" i:"<<i<<endl;
		q.pop();
		i++;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int lo[n];
	for(int i=0;i<n;i++)	cin>>lo[i];
	cout<<check(lo,n)<<endl;
	return 0;
}