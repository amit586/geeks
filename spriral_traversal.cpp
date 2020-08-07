#include<stdio.h>
#include<iostream>
#include<climits>
#include<algorithm>
#include<map>
#include<string.h>
#include<string>
#include<vector>
#include<math.h>
#include<set>
#include<stack>
#include<queue>
#include<chrono>
#include<unordered_map>
#include<unordered_set>

#define mod     1000000007
#define pi      3.1415926535897932384626433832795
#define fio     ios_base::sync_with_stdio(false);cin.tie(NULL);    
#define ll      long long
#define ld      long double
#define pb      push_back
#define all(x)  x.begin(),x.end()
#define f       first
#define s       second
#define int     ll

using namespace std;

int arr[11][11];

main()
{
	fio
	int TC;
	cin>>TC;
	//TC=1;
	while(TC--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>arr[i][j];
		int top,down,left,right,dir = 0;
		top = left = 0;
		down = n-1;
		right = m-1;

		while(top<=down and left <=right)
		{
			if(dir==0)
			{
				for(int i=left;i<=right;i++)
					cout<<arr[top][i]<<" ";
				top++;
			}
			else if(dir==1)
			{
				for(int i=top;i<=down;i++)
					cout<<arr[i][right]<<" ";
				right--;
			}
			else if(dir==2)
			{
				for(int i=right;i>=left;i--)
					cout<<arr[down][i]<<" ";
				down--;
			}
			else 
			{
				for(int i = down;i>=top;i--)
					cout<<arr[i][left]<<" ";
				left++;
			}
			dir = (dir+1)%4;
		}

		cout<<endl;
		
	}
	return 0;
}
