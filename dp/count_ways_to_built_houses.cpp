#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define f(i,j,k)  for(int i=j;i<k;i++)
#define fr(i,j,k) for(int i<=k-1;i>=j;i--)
#define ll long long
#define ld long double

using namespace std;

int main()
{
	fio
	int TC;
	cin>>TC;
	//TC=1;
	while(TC--)
	{
		int n;
		cin>>n;
		int choice1=1;
		int choice2=2;
		int new_choice1;
		for(int i=2;i<=n;i++)
		{
			new_choice1 = choice1+choice2;
			choice2 = 2*choice1 + choice2;
			choice1 = new_choice1;
		}
		cout<<choice2+choice1<<endl;


		
	}
	return 0;
}
