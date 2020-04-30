#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	for(int i=0;i<13;i++)
		cout<<(char)('a'+2*i)<<" "<<(int)('a'+2*i)<<"\t"<<(char)('a'+2*i+1)<<" "<<(int)('a'+2*i+1)<<endl;
	for(int i=0;i<5;i++)
		cout<<(char)('0'+2*i)<<" "<<(int)('0'+2*i)<<"\t"<<(char)('0'+2*i+1)<<" "<<(int)('0'+2*i+1)<<endl;

	return 0;
}