#include <iostream>
using namespace std;

long long lookup[10000];
void _initialize()
{
	for(int i=0;i<10000;i++)
		lookup[i]=-1;
}

long long fibo(long long n)
{
	if(lookup[n]==-1)
	{
		if(n<=2)
			lookup[n]=1;
		else
			lookup[n]=fibo(n-1)+fibo(n-2);
	}
	return lookup[n];
}


long long fibo_(long long n)
{
	if(n<=2)
		return 1;
	else
		return fibo_(n-1)+fibo_(n-2);
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	_initialize();
	cout<<fibo(n)<<endl;
	return 0;
}