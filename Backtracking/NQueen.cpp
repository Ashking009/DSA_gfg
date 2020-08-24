#include <iostream>
#include <cstring>
using namespace std;

int board[10][10];
bool isSafe(int row, int col,int n)
{
    for(int i=0;i<col;i++)
        if (board[row][i])
            return false;
    
    for(int i=row, j=col;i>=0 && j>=0 ;i-- , j--)
        if (board[i][j])
            return false;
    
    for(int i=row, j=col;i<n && j>=0 ;i++ , j--)
        if (board[i][j])
            return false;
    
}
void NQueenRec(int col,int n)
{
    if(n==2 || n==3)
    {
        cout<<-1;
        return;
    }
    if(col>=n)
    {
        cout<<"[";
        for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++){
                    if(board[j][i] == 1)
                        cout<<j+1<<" ";}
            }
            cout<<"]"<<" ";
            return;
    }
    
    for(int i=0;i<n;i++)
    {
        if(isSafe(i,col,n))
        {
            board[i][col]=1;
            NQueenRec(col+1,n);
            board[i][col]=0;

        }
    }
    return ;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    memset(board,0,sizeof(board));
	    NQueenRec(0,n);
	    cout<<endl;
	}
	return 0;
}