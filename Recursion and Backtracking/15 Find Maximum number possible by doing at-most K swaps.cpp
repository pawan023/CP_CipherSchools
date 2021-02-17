// Find Maximum number possible by doing at-most K swaps
// Time Complexity: O(n^k). Space Complexity: O(n). 

#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n" 
using namespace std;

#include <bits/stdc++.h>
using namespace std;
 
void findMaximumNum(string str, int k,string& max, int ctr) {
    if (k == 0)
        return;
 
    int n = str.length();
 
    char maxm = str[ctr];
    for (int j = ctr + 1; j < n; j++) {
        if (maxm < str[j]) maxm = str[j];
    }

    if (maxm != str[ctr]) --k;

    for (int j = ctr; j < n; j++) {
        if (str[j] == maxm) {
            swap(str[ctr], str[j]);

            if (str.compare(max) > 0)
                max = str;
                
            findMaximumNum(str, k, max, ctr + 1);
            swap(str[ctr], str[j]);
        }
    }
}
 
// Driver code
int main() {
    string str = "129814999";
    int k = 4;
 
    string max = str;
    findMaximumNum(str, k, max, 0);
 
    cout << max << endl;
 
    return 0;
}
