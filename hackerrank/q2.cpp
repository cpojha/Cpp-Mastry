// compute factorial of n with t test cases
#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1) return 1;
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int t;
    cin >> t; // Read number of test cases
    while (t--) {
        int n;
        cin >> n; // Read the value of n for each test case
        cout << factorial(n) << endl; // Output the factorial of n
    }
    return 0;
}