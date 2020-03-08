#include<bits/stdc++.h>

using namespace std;

class element
{
public:
	int value;
	int i,j;
};

bool operator <(const element &e1 , const element &e2)
{
	return e1.value<e2.value;
}

bool operator >(const element &e1 , const element &e2)
{
	return e1.value>e2.value;
}

int main(int argc, char const *argv[])
{
	int mat[4][4] = { {10, 20, 30, 40}, 
                    {15, 25, 35, 45}, 
                    {25, 29, 37, 48}, 
                    {32, 33, 39, 50}} ;
    int k;
    cin>>k;

    priority_queue <element,vector<element> ,greater<element>> heap;

    for(int i=0;i<4;i++)
    {	element e ;
    	e.value=mat[0][i];
    	e.i = 0;
    	e.j=i;

    	heap.push(e);
	}

	element next,extracted;
	while(k--)
	{
		//int r=heap.top().i,c =heap.top().j,value = heap.top().value;
		extracted = heap.top();
		next.i = (extracted.i+1);

		next.j = extracted.j;
		next.value = mat[next.i][next.j];
		if(next.i>=4)
			next.value = INT_MAX;
		heap.pop();
		heap.push(next);
		cout<<extracted.value<<" ";
	}
	cout<<extracted.value<<endl;
   
	return 0;
}