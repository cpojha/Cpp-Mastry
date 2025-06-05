//Problem of day of 05-06-2025

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Union-Find (Disjoint Set Union) approach
    int parent[26];
    string smallestEquivalentString(string s1, string s2, string baseStr) {
     
     for(int i=0; i<26; i++){
         parent[i] = i; // Initialize each character to be its own parent
     }
     // build equivalence groups
     for(int i=0; i<s1.length(); i++){
        unionSets(s1[i] - 'a', s2[i] - 'a');
      }
       // Union the characters from s1 and s2, it is stl function right? 
        // it will find the root of each character and merge them
        // so that they are in the same group
        // it will also update the parent of each character to be the smallest character in the group
        // so that we can find the smallest character in the group
        // and it will also update the parent of each character to be the smallest character in the group
        
        string result = "";
        for(char ch: baseStr){
            result += find(ch - 'a') + 'a'; // Find the smallest character in the group and add it to the result
            // How it works in hinglish:
            // yeh ch character ka parent find karega aur usko result mein add karega
            // yeh parent function kaam karega ki ch character ka parent kya hai
            // aur usko result mein add karega
        }
        return result; // Return the final result after processing all characters in baseStr
    }
    // path compression kyu find karna hai?
    // kyuki path compression se hum parent ko update karte hain
    // aur parent ko update karne se hum smallest character ko find karte hain
    // aur smallest character ko find karne se hum result mein add karte hain
    private:

    int find(int x) {// x kya hai? x is the character we are trying to find the parent of
        // x is the index of the character in the parent array
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unionSets(int x , int y){
        int px= find(x), py= find(y); // Find the roots of x and y
        if(px==py){
            return; // If they are already in the same set, do nothing // kyuki yeh already same set mein hain, aur kuch nahi karna hai, a ka parent a hi hai
        }
        if (px<py)
        {
            parent[py] = px; // Make the smaller character the parent of the larger one
        } else {
            parent[px] = py; // Make the smaller character the parent of the larger one
        }
    }

};

int main(){
    Solution sol;
    string s1 = "parker";
    string s2 = "morris";
    string baseStr = "parser";
    string result = sol.smallestEquivalentString(s1, s2, baseStr);
    cout << result << endl; // Output: "makkek"

    return 0;
}

//Example 1:

// Input: s1 = "parker", s2 = "morris", baseStr = "parser"
// Output: "makkek"
// Explanation: Based on the equivalency information in s1 and s2, we can group their characters as [m,p], [a,o], [k,r,s], [e,i].
// The characters in each group are equivalent and sorted in lexicographical order.
// So the answer is "makkek".

// baseStr = "parser" can be represented as follows:
// p -> m
// a -> a smallest char in a is a
// r -> k smallest char in r is k
