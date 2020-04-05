#include <bits/stdc++.h>
#define NO_OF_CHARS 256
using namespace std;

class fAutomata
{
	string text;
	void computeTF(vector <vector <int>> &TF,const string &pat,int M);
	public:
	fAutomata(const string &s);
	void match(const string &pat);
};

 fAutomata::fAutomata(const string &s)
{
	text = s;
}

void fAutomata::computeTF(vector <vector <int>> &TF,const string &pat,int M)
{

	for(int i=0;i<M;i++)
		TF[0][i]=0;
	TF[0][pat[0]]=1;
	
	int lps=0;

	for(int i=1;i<=M;i++)
	{
		for(int j=0;j<NO_OF_CHARS;j++)
			TF[i][j]=TF[lps][j];

		TF[i][pat[i]]=i+1;
		if(i<M)
			lps = TF[lps][pat[i]];
	}

}

void fAutomata::match(const string &pat)
{
	int N = text.size();
	int M = pat.size();
	vector < vector<int> > TF( M+1 , vector <int> (NO_OF_CHARS));

	computeTF(TF,pat,M);

	int state = 0;
	for(int i=0;i<N;i++)
	{
		state = TF[state][text[i]];
		if(state==M)
			cout<<"pattern found at "<<i-M+1<<endl;
	}

	
}

int main(int argc, char const *argv[])
{
	int tc;
	cin>>tc;
	while(tc--)
	{
		string text,pat;
		cin>>text>>pat;
		fAutomata f(text);
		f.match(text);
	}
	return 0;
}