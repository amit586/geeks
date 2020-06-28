#include <bits/stdc++.h>
using namespace std;

int solve(int from,int to,int d)
{
	int x=0,y=0,d1;
	int count=0;
	while(x!=d and y!=d)
	{
		count++;
		if(x==0)
			x+=from;
		else if(y==to)
			y=0;
		else{
			d1 = min(x,to-y);
			x-=d1,y+=d1;
		}
		cout<<"("<<x<<","<<y<<')'<<" ";
	}
	return count;
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int m,n,d;
		cin>>m>>n>>d;
		int c1 = solve(m,n,d);
		cout<<endl;
		int c2 = solve(n,m,d);
		cout<<endl<<min(c1,c2)<<endl;
	}
	return 0;
}