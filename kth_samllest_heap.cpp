#include <iostream>
#include<climits>

using namespace std;

void swap(int *a,int *b)
{
	int temp = *a;
	*a=*b;
	*b=temp;
}

class MinHeap
{
	int heap_size;
	int *harr;
	int capacity;
public:
		MinHeap(int arr[],int n);
		void MinHeapify(int i);
		int extractMin();

		int getMin(){return harr[0];}
		int parent(int i){return (i-1)/2;}
		int left(int i){return i*2+1;}
		int right(int i){return i*2+2;}
		void replaxeMin(int x){harr[0]=x; MinHeapify(0);}
};

MinHeap::MinHeap(int arr[],int n)
{
	heap_size = n;
	harr = arr;

	int i= (heap_size-1)/2;
	while(i>=0)
	{
		MinHeapify(i);
		i--;
	}
}

int MinHeap::extractMin(void)
{
	if(heap_size==0)
		return INT_MAX;
	int root = harr[0];
	if(heap_size>1)
	{
		harr[0]=harr[heap_size-1];
		MinHeapify(0);
	}
	heap_size--;
	return root;
}

void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;

	if(l<heap_size-1 && harr[l]<harr[i])
		smallest = l;
	if(r<heap_size-1 && harr[r]<harr[smallest])
		smallest = r;
	if(smallest!=i)
	{
		swap(&harr[i],&harr[smallest]);
		MinHeapify(smallest);
	}
}


int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int k;
	cin>>k;

	MinHeap mh(arr,n);
	int ans = 0,i=0;
	while(i<k)
	{
		ans = mh.extractMin();
		i++;
	}
	cout<<ans<<endl;

	return 0;
}