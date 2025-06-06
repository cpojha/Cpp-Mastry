// take an aaray like 1122233445 calculate frequncy for each

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1, 1, 2, 2, 2, 3, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int freq[10] = {0}; // Initialize frequency array with 0
    
    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    
    cout << "Frequency of each element:" << endl;
    for(int i = 0; i < 10; i++) {
        if(freq[i] > 0) {
            cout << "Element " << i << " appears " << freq[i] << " times" << endl;
        }
    }
    
    return 0;
}