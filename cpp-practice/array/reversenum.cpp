#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cout << "Enter the number of digits: ";
    cin >> n; // Input the number of digits
    vector<int> arr(n); // Create a vector to store the digits

    cout << "Enter the digits: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Input each digit
    }

    reverse(arr.begin(), arr.end()); // Reverse the vector

    cout << "Reversed number: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i]; // Output the reversed number
    }
    
    return 0; // Return success
}

