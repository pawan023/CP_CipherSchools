// find last non-zero digit in n!

/*
A Simple Solution is to first find n!, then find last non-zero digit of n. 
This solution doesn’t work for even slightly large numbers due to arithmetic overflow.

A Better Solution is based on below recursive formula

Let D(n) be the last non-zero digit in n!
If tens digit (or second last digit) of n is odd
    D(n) = 4 * D(floor(n/5)) * D(Unit digit of n) 
If tens digit (or second last digit) of n is even
    D(n) = 6 * D(floor(n/5)) * D(Unit digit of n)
    
Illustration of formula:

For the numbers less than 10 we can easily find the last non-zero digit by above simple solution, 
i.e., first computing n!, then finding last digit.
D(1) = 1, D(2) = 2, D(3) = 6, D(4) = 4, D(5) = 2,
D(6) = 2, D(7) = 4, D(8) = 2, D(9) = 8.

*/

#include<bits/stdc++.h> 
using namespace std; 
  
// Initialize values of last non-zero digit of 
// numbers from 0 to 9 
int dig[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8}; 
  
int lastNon0Digit(int n) 
{ 
     if (n < 10) 
        return dig[n]; 
  
    // Check whether tens (or second last) digit 
    // is odd or even 
    // If n = 375, So n/10 = 37 and (n/10)%10 = 7 
    // Applying formula for even and odd cases. 
    if (((n/10)%10)%2 == 0) 
        return (6*lastNon0Digit(n/5)*dig[n%10]) % 10; 
    else
        return (4*lastNon0Digit(n/5)*dig[n%10]) % 10; 
} 
  
// Driver code 
int main() 
{ 
    int n = 14; 
    cout << lastNon0Digit(n); 
    return 0; 
}

