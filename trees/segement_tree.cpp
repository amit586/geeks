#include<bits/stdc++.h>
using namespace std;

int getMid(int s,int e){return (s + (e-s)/2);}

int query(int arr[],int ss,int se,int qs,int qe,int *st,int si)
{
	if(ss>qe || se <qs)
		return 0;
	if(qs<=ss && se<=qe)
		return st[si];
	int mid=getMid(si,se);

	return query(arr,ss,mid,qs,qe,st,2*si+1)+
			query(arr,mid+1,se,qs,qe,st,2*si+2);
}

void update(int arr[],int ss,int se,int i,int diff,int *st,int si)
{
	if(ss>i || se<i)
		return ;
	if(i==ss && i==se)
	{
		st[si]+=diff,arr[i]+=diff;
		return ;
	}

	if(i>=ss && i<=se)
	{
		st[si]+=diff;
		int mid = getMid(ss,se);
		update(arr,ss,mid,i,diff,st,2*si+1);
		update(arr,mid+1,se,i,diff,st,2*si+2);
		
	}
}

int constructStUtil(int arr[],int ss,int se,int *st,int si)
{
	if(ss==se)
	{
		st[si]=arr[ss];
		return arr[ss];
	}
	int mid = getMid(ss,se);
	st[si]=constructStUtil(arr,ss,mid,st,2*si+1)+
			constructStUtil(arr,mid+1,se,st,2*si+2);
	return st[si];
}

int *constructSt(int arr[],int n)
{
	int x = (int)(ceil(log2(n)));
	int mx_sz = 2*(int)(pow(2,x))-1;
	int *st = new int[mx_sz];
	constructStUtil(arr,0,n-1,st,0);
	for(int i=0;i<mx_sz;i++)
		cout<<st[i]<<" ";
	cout<<endl;
	return st;
}


int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,q;
		cin>>n>>q;
		int sz=n;
		int *arr = new int[sz];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int *st = constructSt(arr,sz);
		while(q--)
		{
			int qtype;
			cin>>qtype;
			if(qtype==1)
			{
				int l,r;
				cin>>l>>r;
				cout<<"sum between l & r: "<<query(arr,0,n-1,l,r,st,0)<<endl;
			}
			if(qtype==2)
			{
				int i,val;
				cin>>i>>val;
				val = val-arr[i];
				update(arr,0,n-1,i,val,st,0);
				cout<<"query performed "<<endl;
			}
		}

	}
	return 0;
}