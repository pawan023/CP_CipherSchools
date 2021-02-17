// Print all possible combinations of the mobile keyboard 

#include <bits/stdc++.h>
#include <string>

using namespace std;

vector <string> possibleWords(int a[],int n);


int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	  vector <string> res = possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}// } Driver Code Ends


vector <string> words(string s, vector<string> map){
    if(s.size()==0){
        vector <string> temp;
        temp.push_back("");
        return temp;
    }
    char c = s[0];
    string rest = s.substr(1);
    vector <string> v = words(rest,map);
    vector <string> final;
    string str = map[(int)c];
    for(int i=0; i<str.size();i++){
        for(int j=0; j<v.size();j++){
            final.push_back(str[i]+v[j]);
        }
    }
    return final;
}

vector <string> possibleWords(int a[],int N)
{
    //Your code here
    vector<string> map(10,"");
    map[2] = "abc"; map[3] = "def"; map[4] = "ghi"; map[5] = "jkl"; map[6] = "mno";
    map[7] = "pqrs"; map[8] = "tuv"; map[9] = "wxyz";
    
    string s ;
    for(int i=0; i<N; i++){ s += a[i]; }
    
    vector<string> res = words(s,map);
    sort(res.begin(),res.end());
    return res;
}
