#include<bits/stdc++.h>
using namespace std;  

void updateValueUtil(int *st,int ss,int se,int si,int i,int diff)
{
	if(i<ss || i>se)
		return;
	if(ss==se && ss==i)
	{st[si]^=diff;return;}
	
	st[si]^=diff;
	int mid = (ss+se)/2;
	updateValueUtil(st,ss,mid,2*si+1,i,diff);
	updateValueUtil(st,mid+1,se,2*si+2,i,diff);
}

void updateValue(int arr[],int *st,int n,int i,int val)
{
	int diff = arr[i]^val;
	arr[i]^=diff;
	updateValueUtil(st,0,n-1,0,i,diff);
}

int getXorUtil(int *st,int ss,int se,int qs,int qe,int si)
{
	if(qe<ss || se<qs)
		return 0;
	if(qs<=ss && se<=qe)
		return st[si];
	int mid = (ss+se)/2;
	return getXorUtil(st,ss,mid,qs,qe,2*si+1)^getXorUtil(st,mid+1,se,qs,qe,2*si+2);
}


int getXor(int *st,int  n, int l, int r)
{
	return getXorUtil(st,0,n-1,l,r,0);
} 

int constructSTUtil(int arr[],int ss,int se,int *st,int si)
{
	if(ss==se)
	{
		st[si]=arr[ss];
		return st[si];
	}

	int mid = (ss+se)/2;
	st[si]=constructSTUtil(arr,ss,mid,st,2*si+1)^constructSTUtil(arr,mid+1,se,st,2*si+2);
	return st[si];	
}

int *constructST(int arr[],int n)
{
	int mx_sz = 2*pow(2,(int)(ceil(log2(n))))-1;
	int *st = new int[mx_sz];
	constructSTUtil(arr,0,n-1,st,0);
	cout<<"st: ";
	for(int i=0;i<mx_sz;i++)
		cout<<st[i]<<" ";
	cout<<endl;
	return st;
}

int main()
{
	int arr[] = {1, 3, 5, 7, 9, 11}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int *st = constructST(arr, n); 
    printf("Xor of values in given range = %d\n",  
            getXor(st, n, 1, 3)); 
    updateValue(arr, st, n, 1, 10); 
    printf("Updated xor of values in given range = %d\n", 
             getXor(st, n, 1, 3)); 
    return 0; 
}