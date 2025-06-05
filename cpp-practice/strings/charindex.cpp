#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "chandra";
    for (int i = 0; i < s.length(); i++) {
        cout << s[i] << " ";
        int b = s[i] - 'a' + 1; // Convert character to its corresponding index (1-based)
        cout << b;
    }

    return 0;
}
