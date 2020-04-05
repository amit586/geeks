#include <iostream>
using namespace std;

int main() {
    int tc;
    cin>>tc;
    while(tc--)
    {
        string t;
        cin>>t;
        int lsp[t.size()];
        lsp[0]=0;
        int len = 0,i=1;
        
        while(i<t.size())
        {
            if(t[i]==t[len])
            {
                len++;
                lsp[i]=len;
                i++;
            }
            else
            {
                if(len==0)
                {
                    lsp[i]=0;
                    i++;
                }
                else
                    len = lsp[len-1];
            }
        }
        cout<<len<<endl;
    }
	return 0;
}