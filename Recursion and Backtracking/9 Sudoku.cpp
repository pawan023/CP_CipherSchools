#include <bits/stdc++.h>
using namespace std;

// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  

bool SolveSudoku(int grid[N][N]);

void printGrid(int grid[N][N]);

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		cout<<endl;
		if (SolveSudoku(grid) == true)  
            printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}// } Driver Code Ends

bool isSafe(int grid[N][N], int row, int col, int value){
    for(int i=0; i<N; i++){ // looking for value in that row & col
        if(grid[row][i]==value or grid[i][col]==value) return false;
    }
    // checking submatrix
    // to get top left cell of any submatix( of root n*rootN)
    // general formula = { r=(row/3)*3 , c=(col/3)*3 }
    int sm = sqrt(N);
    int r=(row/sm)*sm , c=(col/sm)*sm;
    // r= row-(row%sm) , c= (col-col%sm)
    for(int i=r; i<r+sm; i++){
        for(int j=c; j<c+sm; j++){
            if(grid[i][j]==value) return false;
        }
    }
    return true;
}
bool helper(int grid[N][N], int row, int col){
    if(row==N){
        //printGrid(grid);
        return true;
    }
    int next_row, next_col;
    if(col==N-1) { next_row = row+1, next_col = 0; }
    else { next_row = row, next_col = col+1; }
    
    if(grid[row][col]!=0) return helper(grid, next_row, next_col);
    else{
        for(int option=1; option<=N; option++){
            if(isSafe(grid,row,col,option)){
                grid[row][col] = option;
                if(helper(grid, next_row, next_col)) return true;
                grid[row][col] = 0;
            }
        }
    }
    return false;
}
bool SolveSudoku(int grid[N][N]) {
    return helper(grid,0,0);
}

void printGrid (int grid[N][N]) {
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<grid[i][j]<<" ";
        } cout<<endl;
    }
}

/*

//input
3 0 6 5 0 8 4 0 0 
5 2 0 0 0 0 0 0 0 
0 8 7 0 0 0 0 3 1 
0 0 3 0 1 0 0 8 0 
9 0 0 8 6 3 0 0 5 
0 5 0 0 9 0 6 0 0 
1 3 0 0 0 0 2 5 0 
0 0 0 0 0 0 0 7 4 
0 0 5 2 0 6 3 0 0 
//output
3 1 6 5 7 8 4 9 2 
5 2 9 1 3 4 7 6 8 
4 8 7 6 2 9 5 3 1 
2 6 3 4 1 5 9 8 7 
9 7 4 8 6 3 1 2 5 
8 5 1 7 9 2 6 4 3 
1 3 8 9 4 7 2 5 6 
6 9 2 3 5 1 8 7 4 
7 4 5 2 8 6 3 1 9 

*/
