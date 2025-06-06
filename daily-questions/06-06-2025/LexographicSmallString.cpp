#include<bits/stdc++.h>
using namespace std;


//stack approch use 
// 1. We can use a stack to keep track of the characters in the string.
// 2. We can iterate through the string and for each character, we can check if it is smaller than the top of the stack.
// 3. If it is smaller, we can pop the top of the stack and add it to the result string.
// 4. If it is not smaller, we can push the character onto the stack.
// 5. We can repeat this process until we have processed all the characters in the string.
// 6. Finally, we can pop all the remaining characters from the stack and add them to the result string.

class Solution {
public:
// Helper function to find the minimum character in the frequency array
    char findMinChar(vector<int>& freq) {
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                return 'a' + i;
            }
        }
        return 'a'; // This should never happen given the problem constraints
    }
// Function to find the lexicographically smallest string
    string robotWithString(string s) {
     
        stack<char> st;
       string res = "";
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

// Iterate through the string and process each character
    for(char ch: s){
        char minChar = findMinChar(freq);
        while (!st.empty() && st.top() <= minChar) {
            res += st.top();
            st.pop();
        }
        st.push(ch);
        freq[ch - 'a']--;
    }
// After processing all characters, pop any remaining characters from the stack
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
        // Return the result string
        return res;
    }
};

int main() {
    Solution sol;
    string s;
    cin >> s;
    cout << sol.robotWithString(s) << endl;
    return 0;
}
// Example 1:

// Input: s = "zza"
// Output: "azz"
// Explanation: Let p denote the written string.
// Initially p="", s="zza", t="".
// Perform first operation three times p="", s="", t="zza".
// Perform second operation three times p="azz", s="", t="".
// Example 2:

// Input: s = "bac"
// Output: "abc"
// Explanation: Let p denote the written string.
// Perform first operation twice p="", s="c", t="ba". 
// Perform second operation twice p="ab", s="c", t="". 
// Perform first operation p="ab", s="", t="c". 
// Perform second operation p="abc", s="", t="".
// Example 3:

// Input: s = "bdda"
// Output: "addb"
// Explanation: Let p denote the written string.
// Initially p="", s="bdda", t="".
// Perform first operation four times p="", s="", t="bdda".
// Perform second operation four times p="addb", s="", t="".
 

// Constraints:

// 1 <= s.length <= 105
// s consists of only English lowercase letters.