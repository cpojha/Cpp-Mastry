#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int count = 0;
    
    for (int i = 0; i < n; ++i){
        int p, v, t;
        cin >> p >> v >> t;
        
        // Check if at least 2 members can solve the problem
        if(p + v + t >= 2){
            count++;
        }
    }
    
    cout << count << endl; // Output after processing all teams
    
    return 0;
}