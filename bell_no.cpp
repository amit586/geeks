#include<iostream>
using namespace std;

long long bell(int n)
{
	int	bl[n][n];
	bl[0][0]=1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j==0)
				bl[i][j]=bl[i-1][i-1];
			else
				bl[i][j]=bl[i-1][j-1]+bl[i][j-1];
		}
	}
	return bl[n-1][n-1];
}

int main()
{
	int n;
	cin>>n;
	cout<<bell(n)<<endl;
}
