// Merge 3 array 
/*
Expected Time Complexity: O(N + M + P)
Expected Auxiliary Space: O(N + M + P) for the resultant array only.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> mergeThree(vector<int>& A, vector<int>& B, vector<int>& C) {
    
    vector<int>  v;
    int i=0,j=0,k=0;
    int s1=A.size(), s2=B.size(), s3=C.size();
    
    while(i<s1 && j<s2 && k<s3){
        int m=min(A[i],min(B[j],C[k]));
        v.push_back(m);
        if(A[i]==m) i++;
        else if(B[j]==m) j++;
        else k++;
    }
    
    while(i<s1 && j<s2){
        if(A[i]<=B[j]) { v.push_back(A[i++]); }
        else { v.push_back(B[j++]); }
    }
    while(j<s2 && k<s3){
        if(B[j]<=C[k]) { v.push_back(B[j++]); }
        else { v.push_back(C[k++]); }
    }
    while(i<s1 && k<s3){
        if(A[i]<=C[k]) { v.push_back(A[i++]); }
        else { v.push_back(C[k++]); }
    }
    
    while(i<s1) v.push_back(A[i++]);
    while(j<s2) v.push_back(B[j++]);
    while(k<s3) v.push_back(C[k++]);
    
    return v;
} 



