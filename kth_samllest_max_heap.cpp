#include <iostream>
#include<climits>

using namespace std;

void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b=temp;
}

class MaxHeap
{
    int capacity;
    int heap_size;
    int *harr;
public:
    MaxHeap(int arr[],int n);
    int extractMax(void);
    void MaxHeapify(int i);
    
    int parent(int i){return (i-1)/2;}
    int left(int i){return i*2+1;}
    int right(int i){return i*2+2;}
    
};

MaxHeap::MaxHeap(int arr[],int n)
{
    heap_size=n;
    harr=arr;
    int i=(heap_size-1)/2;
    while(i>=0)
    {
        MaxHeapify(i);
        i--;
    }
}

int MaxHeap::extractMax(void)
{
    if(heap_size==0)
        return INT_MAX;
    int root = harr[0];
    if(heap_size>1)
    {
        harr[0]=harr[heap_size-1];
        MaxHeapify(0);
    }
    heap_size--;
    return root;
}


void MaxHeap::MaxHeapify(int i)
{
    int l=left(i),r=right(i),largest = i;
    
    if(l<heap_size && harr[l]>harr[i])
        largest = l;
    if(r<heap_size && harr[r]>harr[largest])
        largest =r;
    if(largest!=i)
    {
        swap(&harr[i],&harr[largest]);
        MaxHeapify(largest);
    }
}



int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    MaxHeap mh(arr,n);
	    int i=0;
	    while(i<k)
	    {
	        cout<<mh.extractMax()<<" ";
            i++;
	    }
	    cout<<endl;
	    
	}
	return 0;
}