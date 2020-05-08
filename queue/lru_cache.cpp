// { Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Node{
public:
	int key,value;
	Node *next,*prev;
	Node(int k,int v):key(k),value(v),next(NULL),prev(NULL){};
};

// design the class:

class LRUCache
{
private:
	Node *head,*tail;
	unordered_map<int,Node*> hash;
	int sz,mx_sz;
public:
    LRUCache(int cap)
    {
    	head=NULL;
    	sz=0,mx_sz=cap;
        // constructor for cache
    }
    
    int get(int key)
    {
    	if(hash.find(key)!=hash.end())
    	{
    		makeFirst(hash[key]);
    		return hash[key]->value;
    	}
    	else
    		return -1;
        // this function should return value corresponding to key
    }

   
    void set(int key, int value)
    {
        // storing key, value pair

        if(hash.find(key)!=hash.end())
        {
        	makeFirst(hash[key]);
        	hash[key]->value=value;
        }
        else /// not found ///
        {
        	if(head==NULL)
        	{
        		head=new Node(key,value);
        		tail=head;
        		hash[key]=head;
        		sz++;
        		return;
        	}

        	Node *n = new Node(key,value);
        	n->next=head;
        	head->prev=n;
        	head=n;
        	sz++;
        	hash[key]=head;
        	if(sz>mx_sz)
        	{
        		Node *temp = tail;
        		hash.erase(temp->key);
        		tail=tail->prev;
        		tail->next=NULL;
        		sz--;
        		delete temp;
        	}
        }
    }

    void makeFirst(Node *n)
    {
    	if(n==head)
    		return;

    	if(n->next==NULL)
    	{
    		tail=n->prev;
    		n->prev->next=NULL;
    		n->prev = NULL;
    		head->prev=n;
    		n->next=head;
    		head=n;
    		return;
    	}

    	n->prev->next = n->next;
    	n->next->prev=n->prev;
    	n->next=head;
    	n->prev=NULL;
    	head->prev=n;
    	head=n;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends