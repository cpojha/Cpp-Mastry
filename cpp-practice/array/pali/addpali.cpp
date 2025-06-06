// Reverse and add( palinrome number)
// check if 89 is a palindrome exit and print if not add 89+89+98=197 if also not repear adding process until a palindrome is found

#include <iostream>
#include <climits>
using namespace std;

int reverse(int n) {
    int rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

bool isPalindrome(int n) {
    return n == reverse(n);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    while (!isPalindrome(num)) {
        int rev = reverse(num);
        cout << "Not a palindrome: " << num << ", reversing gives: " << rev << endl;
        
        // Check if addition would cause overflow
        if (num > INT_MAX - rev) {
            cout << "Number would exceed integer limit. Breaking..." << endl;
            break;
        }
        
        num += rev;
        cout << "New number after addition: " << num << endl;
    }

    if (isPalindrome(num)) {
        cout << "Found palindrome: " << num << endl;
    } else {
        cout << "Process terminated due to overflow risk." << endl;
    }
    
    return 0;
}