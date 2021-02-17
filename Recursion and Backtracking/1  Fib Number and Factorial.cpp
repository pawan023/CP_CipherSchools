//  Fibonacci Number

//recursive
long long fib(int n){
    if(n<2) return n;
    return fib(n-1)+fib(n-2);
}

// tail recursive
long long fib(int n, int a = 0, int b = 1){ 
    if (n == 0) return a; 
    if (n == 1) return b; 
    return fib(n - 1, b, a + b); 
}

// Factorial

//recursive
long long fact(int n){
    if (n == 0) return 1;
    return n*fact(n-1);
}

//tail recursive
long long fact(int n, int f=1){
    if (n == 0) return f;
    return fact(n-1, n*f);
}

// Driver code
int main() {
    cout << fact(5);
    cout<< fib(5);
    return 0;
}
