// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node* next;
};

void printList(struct node *node)
{
    while(node!=NULL){
        cout<<node->data<<' ';
        node = node->next;
    }
    printf("\n");
}

void push(struct node** head_ref, int new_data)
{
    struct node* new_node =	(struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

struct node* findIntersection(struct node* head1, struct node* head2);

int main()
{
    long test;
    cin>>test;
    while(test--)
    {
        struct node* a = NULL;
        struct node* b = NULL;
        int n, m, tmp;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>tmp;
            push(&a, tmp);
        }
        cin>>m;
        for(int i=0; i<m; i++)
        {
            cin>>tmp;
            push(&b, tmp);
        }
        printList(findIntersection(a, b));
    }
    return 0;
}
// } Driver Code Ends
/*
structure of the node is as
struct node
{
	int data;
	struct node* next;
};
*/
struct node* findIntersection(struct node* head1, struct node* head2)
{
    unordered_map<int,int> hash;
    while(head2)
    {
    	hash[head2->data]++;
    	head2=head2->next;
    }
    
    vector<int> ans;
    while(head1)
    {
    	if(hash[head1->data]>0)
    		ans.push_back(head1->data);
    	head1=head1->next;
    }
    sort(ans.begin(),ans.end());
    node *inter = NULL;
    for(int i=0;i<ans.size();i++)
    	push(&inter,ans[i]);
    return inter;
}
