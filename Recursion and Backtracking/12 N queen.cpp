#include<bits/stdc++.h>
using namespace std;

// N queen
// printing all possible correct configuration
bool isSafe(int n, int row, int col, vector<vector<int>> &chess){
    for(int r=row-1; r>=0; r--){ //checking all above rows for same column
        if(chess[r][col]) return false;
    }
    for(int r=row-1, c=col-1; r>=0 && c>=0; r--,c--){ // checking left diag 
        if(chess[r][c]) return false;
    }
    for(int r=row-1, c=col+1; r>=0 && c<n; r--,c++){ // checking right diag 
        if(chess[r][c]) return false;
    }
    return true;
}

void print(vector<vector<int>> &chess){
	for(int i=0;i<chess.size();i++){
		for(int j=0;j<chess.size();j++){
			cout<<chess[i][j]<<" ";
		} cout<<endl;
	} cout<<endl; cout<<endl;
}

void nQueen(int n, int row, vector<vector<int>> &chess ){
    if(row==n){
        print(chess);
        return;
    }
    for(int col=0; col<n; col++){
        if(isSafe(n,row,col,chess)){
            chess[row][col] = 1;
            nQueen(n,row+1,chess);
            chess[row][col] = 0;
        }
    }
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> chess(n, vector<int> (n,0));
        nQueen(n,0,chess);
    }
}
