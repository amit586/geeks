#include <bits/stdc++.h>
using namespace std;

bool inRow(int arr[9][9],int num,int row)
{
    for(int i=0;i<9;i++)
        if(arr[row][i]==num)
            return true;
    return false;
}

bool inCol(int arr[9][9],int num,int col)
{
    for(int i=0;i<9;i++)
        if(arr[i][col]==num)
            return true;
    return false;
}

bool inBox(int arr[9][9],int num,int row,int col)
{
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(arr[i+row][j+col]==num)
                return true;
    return false;
}

bool isAllowed(int arr[9][9],int num,int row,int col)
{
    return !inRow(arr,num,row) && !inCol(arr,num,col) && !inBox(arr,num,row-row%3,col-col%3);
}

bool findEmpty(int arr[9][9],int &row,int &col)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(arr[i][j]==0)
            {
                row = i;
                col=j;
                return true;
            }
            
        }
    }
    return false;
}

bool solveSudoku(int arr[9][9])
{
    int row=0,col=0;
    
    if(!findEmpty(arr,row,col))
        return true;
    //cout<<"row "<<row<<" col "<<col<<endl;
    for(int i=1;i<=9;i++)
    {
        if(isAllowed(arr,i,row,col))
        {
            arr[row][col] = i;
            if(solveSudoku(arr))
                return true;
            arr[row][col]=0;
        }
    }
    return false;
}


int main() {
	int tc;
	cin>>tc;
	while(tc--)
	{
	    int grid[9][9];
	    memset(grid,0,sizeof(grid));
	    
	    for(int i=0;i<9;i++)
	       for(int j=0;j<9;j++)
	        cin>>grid[i][j];
	    
        solveSudoku(grid);
       
        for(int i=0;i<9;i++)
	    {
	        for(int j=0;j<9;j++)
	            cout<<grid[i][j]<<" ";
	        cout<<endl;
	    }
	   
	}
	return 0;
}