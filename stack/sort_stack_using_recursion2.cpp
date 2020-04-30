// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
	void insertSorted(stack<int> &s,int n);

};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}// } Driver Code Ends
/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
	if(s.empty())
		return;
	int temp = s.top();
	s.pop();
	sort();
	insertSorted(s,temp);

}

void SortedStack::insertSorted(stack<int> &s,int n)
{
	if(s.empty())
	{
		s.push(n);
		return;
	}
	int temp = s.top();
	if(temp>n)
		s.pop(),insertSorted(s,n),s.push(temp);
	else
		s.push(n);
}
