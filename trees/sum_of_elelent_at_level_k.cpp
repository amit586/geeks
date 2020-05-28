#include <bits/stdc++.h>
using namespace std;

// void buildTree(string &s,int start,int end,int k,int &sum)
// {
// 	if(s[start+1]==')')
// 		return ;
// 	if(k==0 )
// 	{
// 		cout<<s[start+1]<<": "<<start<<" "<<end<<endl;
// 		sum+= s[start+1]-'0';
// 		return ;
// 	}

// 	int part = start+2,count=1;
// 	while(count!=0 && part<end)
// 		if(s[part++]=='(')
// 			count++;
// 		else if(s[part++]==')')
// 			count--;
// 	cout<<start<<":"<<s[start]<<" "<<part-1<<":"<<s[part-1]<<" "<<end<<":"<<s[end]<<endl;
// 	buildTree(s,start+2,part-1,k-1,sum);

// 	buildTree(s,part,end,k-1,sum);
// }

int main(int argc, char const *argv[])
{
	string tree = "(0(5(6()())(4()(9()())))(7(1()())(3()())))";
	int sum=0;
	// buildTree(tree,0,tree.size()-1,2,sum);
	int k=2;
	int level=-1;
	for(int i=0;i<tree.size();i++)
	{
		if(tree[i]==')')
			level--;
		else if(tree[i]=='(')
			level++;
		else if(level==k)
			sum+=tree[i]-'0';
	}

	cout<<sum<<endl;
	return 0;
}