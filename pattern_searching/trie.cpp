#include<bits/stdc++.h>
#define ALPHABET_SIZE 26
using namespace std;

class TrieNode
{
public:
	TrieNode *children[ALPHABET_SIZE];
	bool isEndOfWord;
	int at(char c);
	TrieNode();
	void insertWord(const string &word,TrieNode *root);
	bool searchWord(const string &word,TrieNode *root);
};

TrieNode::TrieNode()
{
	for(int i=0;i<ALPHABET_SIZE;i++)
		children[i]=NULL;
	isEndOfWord=false;
}

int TrieNode::at(char c)
{
	return c-'a';
}

void TrieNode::insertWord(const string &word, TrieNode *root)
{	
	TrieNode *temp=root;
	for(int i=0;i<word.size();i++)
	{
		if(!temp->children[at(word[i])])
			temp->children[at(word[i])] = new TrieNode();
	
		temp = temp->children[at(word[i])];
	}
	temp->isEndOfWord=true;
}

bool TrieNode::searchWord(const string &word,TrieNode *root)
{
	TrieNode *temp = root;
	for(int i=0;i<word.size();i++)
	{
		//cout<<"END of word "<<word[i]<<" -> "<<temp->isEndOfWord<<endl;
		if(!temp->children[at(word[i])])
			return false;
		temp = temp->children[at(word[i])];
	}
	//cout<<"END of word last -> "<<temp->isEndOfWord<<endl;
	if(temp->isEndOfWord==true)
		return true;
	else
		return false;
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		TrieNode *root = new TrieNode();
		string word;
		for(int i=0;i<n;i++)
		{
			cin>>word;
			root->insertWord(word,root);
		}
		cin>>word;
		cout<<root->searchWord(word,root)<<endl;
	}
	return 0;
}
