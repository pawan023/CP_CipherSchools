//----------------------------------------------------------------------------------
// Excel Sheet Column Title
//----------------------------------------------------------------------------------
/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...
    
Input: 1
Output: "A"

Input: 28
Output: "AB"

Input: 701
Output: "ZY"
*/
//----------------------------------------------------------------------------------

class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while(n){
            char c = (n-1)%26 + 'A';
            s = c + s;
            n = (n-1)/26;
        }
        return s;
    }
};

//----------------------------------------------------------------------------------
