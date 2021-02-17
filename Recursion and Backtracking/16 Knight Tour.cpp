// knight tour

#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n" 
using namespace std;

void printChess(vector<vector<int>> &v){
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v.size(); j++)
			cout<<v[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl<<endl;
}

void knightTour(vector<vector<int>> &v, int row,int col,int move){
	//cell out of board or cell already visited
	if(row <0 or col<0 or row >= v.size() or col >= v.size() or v[row][col]!=0){
		return;
	}
	else if(move==v.size()*v.size()){
		v[row][col]=move; // visit the last required cell
		printChess(v); //print answer
		v[row][col]=0; //mark cell as unvisted again
		return;
	}
	v[row][col]=move; //mark visited
	//explore all 8 options
	knightTour(v,row-2,col+1,move+1);
	knightTour(v,row-1,col+2,move+1);
	knightTour(v,row+1,col+2,move+1);
	knightTour(v,row+2,col+1,move+1);
	knightTour(v,row+2,col-1,move+1);
	knightTour(v,row+1,col-2,move+1);
	knightTour(v,row-1,col-2,move+1);
	knightTour(v,row-2,col-1,move+1);
	// mark unmarked, backtrack
	v[row][col]=0;
}

int main(){
    FAST_IO;
    int n,row,col;
    cin>>n>>row>>col;
    vector<int> rows(n,0);
    vector<vector<int>> chess(n,rows);
    printChess(chess);
    int move=1; // n^2-1 more cells to visit
	knightTour(chess, row, col, move);
}

