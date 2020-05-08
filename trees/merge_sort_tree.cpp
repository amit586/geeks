#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

void merge(int st[][MAX],pair<int,int> p1,pair<int,int> p2,int dest,int src)
{
	int start = min(p1.first,p2.first);
	int i=p1.first,j=p2.first,k=start;

	while(i<=p1.second && j<=p2.second)
	{
		if(st[src][i]<st[src][j])
			st[dest][k++]=st[src][i++];
		else
			st[dest][k++]=st[src][j++];
	}

	while(i<=p1.second)
		st[dest][k++]=st[src][i++];
	while(j<=p2.second)
		st[dest][k++]=st[src][j++];

}

pair<int,int> buildSegement(int st[][MAX],int ss,int se,int levl,int arr[],int n)
{
	if(ss==se)
	{
		st[levl][ss]=arr[se];
		return {ss,ss};
	}

	int mid = (ss+se)/2;
	pair<int,int> p1 = buildSegement(st,ss,mid,levl+1,arr,n);
	pair<int,int> p2 = buildSegement(st,mid+1,se,levl+1,arr,n);
	int lvalue = min(p1.first,p2.first);
	int rvalue = max(p1.second,p2.second);
	merge(st,p1,p2,levl,levl+1);
	return {lvalue,rvalue};
}

tuple<int,int> query(int st[][MAX],int s,int e,int levl,int l,int r,int k,int &ans)
{
	if(s==l && r==l)
		ans = st[levl][l+k];
	if(r<s || l>e)
		return {-1,-1};
	if(l<=s && e<=r)
		return {s,e};
	int mid = (s+e)/2;
	tuple<int,int> q1,q2;
	q1=query(st,s,mid,levl+1,l,r,k,ans);
	q2 = query(st,mid+1,e,levl+1,l,r,k,ans);
	tuple<int,int> res = {(get<0>(q1)==-1?s:get<0>(q1)),(get<1>(q2)==-1?e:get<1>(q2))};
	if(get<0>(res)==l && get<1>(res)==r)
		ans = st[levl][l+k];
	return res;
}

int main(int argc, char const *argv[])
{
	int n,q;
	cin>>n>>q;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	int levl = (int)ceil(log2(n))+1;
	int mx_sz = 2*pow(2,levl)-1;

	int st[levl][MAX];
	buildSegement(st,0,n-1,0,arr,n);

	while(q--)
	{
		int l,r,k;
		cin>>l>>r>>k;
		l--,r--,k--;
		int ans=-1;
		query(st,0,n-1,0,l,r,k,ans);
		cout<<ans<<endl;
	}
	return 0;
}