//----------------------------------------------------------------------------------
// Excel Sheet Column Number
//----------------------------------------------------------------------------------
/*
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
    
Input: "A"
Output: 1

Input: "AB"
Output: 28

Input: "ZY"
Output: 701

*/
//----------------------------------------------------------------------------------

class Solution {
public:
    int titleToNumber(string s) {
        int decimal=0;
        for(char c: s) decimal = decimal*26 + (c-64);
        return decimal;
    }
};

//----------------------------------------------------------------------------------



