#include <bits/stdc++.h>
using namespace std;

void solve(int n,char x,char y)
{
	if(n==1)
	{
		cout<<"move "<<n<<" from "<<x<<" to "<<y<<endl;
		return;
	}
	char z = 'a'+'b'+'c'-x-y;
	solve(n-1,x,z);
	cout<<"move "<<n<<" from "<<x<<" to "<<y<<endl;
	solve(n-1,z,y);

}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		solve(n,'a','c');
	}
	return 0;
}