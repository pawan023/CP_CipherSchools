// Generate Parentheses

/*

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Input: n = 1
Output: ["()"]

*/

// 1 Recursive (backtracking)
// We use l and r to denote the number of (s and )s. If l < n, we can add a (. If r < l, we can add a ).

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> parens;
        string paren;
        generate(n, 0, 0, paren, parens);
        return parens;
    }
private:
    void generate(int n, int l, int r, string paren, vector<string>& parens) {
        if (l == n && r == n) {
            parens.push_back(paren);
        } else {
            if (l < n) {
                generate(n, l + 1, r, paren + '(', parens);
            }
            if (r < l) {
                generate(n, l, r + 1, paren + ')', parens);
            }
        }
    }
};

// 2 Iterative
// This idea is taken from the official solution.

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (!n) {
            return {""};
        }
        vector<string> parens;
        for (int i = 0; i < n; i++) {
            for (string l : generateParenthesis(i)) {
                for (string r : generateParenthesis(n - 1 - i)) {
                    parens.push_back('(' + l + ')' + r);
                }
            }
        }
        return parens;
    }
};
 
