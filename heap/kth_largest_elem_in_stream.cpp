#include <iostream>
using namespace std;
void swap(int &a,int &b)
{
	int temp=b;
	b=a;
	a=temp;
}

void heapify(int v[],int i,int n)
{
	int mn = i;
	int l = 2*i+1,r=2*i+2;
	if(l<n && v[l]<v[mn])
		mn=l;
	if(r<n && v[r]<v[mn])
		mn=r;
	if(mn!=i)
		swap(v[i],v[mn]),heapify(v,mn,n);
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,k;
		cin>>k>>n;
		int  v[n];
		int mnHeap[k];
		int lastP = k;
		for(int i=0;i<n;i++) cin>>v[i];

		for(int i=0;i<n;i++)
		{
			if(lastP>0)
			{
				mnHeap[lastP-1]=v[i];
				heapify(mnHeap,lastP-1,k);
				lastP--;
				if(lastP>0)
					cout<<-1<<" ";
				else
					cout<<mnHeap[lastP]<<" ";
			}
			else
			{			
				mnHeap[0]=max(mnHeap[0],v[i]);
				heapify(mnHeap,0,k);
				cout<<mnHeap[0]<<" ";
			}
		}
		cout<<endl;
	}

	return 0;
}