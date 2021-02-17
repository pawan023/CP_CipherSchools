#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n" 
#define Max 1000000007
using namespace std;

// Rat Maze With Multiple Jumps. forward ans downward
// If multiple solutions exist, the shortest earliest hop will be accepted. 
// For the same hop distance at any point, forward will be preferred over downward.

bool isSafe(vector<int> maze[], int N, vector<vector<int>> &solution, int x, int y){
    return (x<N && y<N && maze[x][y]!=0 && solution[x][y]==0);
}

bool ratMazeSolvable( vector<int> maze[], int N, vector<vector<int>> &solution, int x, int y){
    if(x==N-1 && y==N-1) { // return true if goal is reached
        solution[x][y] = 1;
        return true;
    }
    if(isSafe(maze,N,solution,x,y)){ //check if its safe to jump
        solution[x][y] = 1;//mark cell as visited
        for(int jump = 1; jump<=maze[x][y]; jump++){// loop through 1..j jumps that u can make
            if( ratMazeSolvable(maze,N,solution,x,y+jump) ) return true; //first jump to forward cell
            // if u fail to reach end from forward try down cell
            if( ratMazeSolvable(maze,N,solution,x+jump,y) ) return true;
            // return true if u can reach end from there
        }
        // if none of this work's
        // BACKTRACK: unmark (x, y) as a part of solution 
        solution[x][y] = 0;
        return false;
    }
    return false;
}

void print(int N, vector<vector<int>> &solution){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<solution[i][j]<<" ";
        } cout<<"\n";
    }
}

void solve(int N, vector<int> maze[]) {
    vector<vector<int>> solution (N, vector<int> (N,0));
    if(ratMazeSolvable(maze,N,solution,0,0)){
        print(N,solution);
    }
    else{
        cout<<-1<<"\n";
    }
}

//------------------------------------------
int main() {
	FAST_IO
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> maze[n];
        for (int i = 0; i < n; i++) {
            maze[i].assign(n, 0);
            for (int j = 0; j < n; j++) cin >> maze[i][j];
        }
        solve(n, maze);
        cout<<endl;
    }
    return 0;
}
//--------------------

/*
2
4
2 1 0 0
3 0 0 1
0 1 0 1
0 0 0 1
3
2 3 4
3 4 2
1 1 0
*/
