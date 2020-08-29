#include <iostream>
using namespace std;

bool isRowSafe(int arr[][9],int row, int num)
{
    for(int i=0;i<9;i++)
    {
        if(arr[row][i]==num)
        return false;
    }
    return true;
}
bool isColSafe(int arr[][9],int col, int num)
{
    for(int i=0;i<9;i++)
    {
        if(arr[i][col]==num)
        return false;
    }
    return true;
}
bool isBoxSafe(int arr[][9],int row,int col, int num)
{
    int rowS = row - row%3;
    int colS = col - col%3;
    for(int i=rowS;i<rowS+3;i++)
    {
        for(int j=colS;j<colS+3;j++)
        {
            if(arr[i][j]==num)
            return false;
        }
    }
    return true;
}

bool isSafe(int arr[][9],int row, int col, int num)
{
    if(!isRowSafe(arr,row,num))
        return false;
    if(!isColSafe(arr,col,num))
        return false;
    if(!isBoxSafe(arr,row,col,num))
        return false;
    
    return true;
}

bool SudokuSolver(int arr[][9])
{
    int row = -1;
    int col = -1;
    bool isEmpty = false;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
        {
            if(arr[i][j] == 0)
            {
                isEmpty = true;
                row=i;
                col=j;
                break;
            }
        }
        if(isEmpty)
        break;
    }
    if(!isEmpty)
    return true;
    
    for(int i=1; i<=9; i++)
    {
        if(isSafe(arr , row, col, i))
        {
            arr[row][col] = i;
            if(SudokuSolver(arr))
                return true;
            arr[row][col]=0;
        }
    }
    return false;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int arr[9][9];
	    for(int i=0;i<9;i++)
	    {
	        for(int j=0;j<9;j++)
	        cin>>arr[i][j];
	    }
	    SudokuSolver(arr);
	    for(int i=0;i<9;i++)
	    for(int j=0;j<9;j++)
	    cout<<arr[i][j]<<" ";
	    cout<<endl;
	}
	return 0;
}