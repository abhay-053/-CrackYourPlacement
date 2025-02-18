//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int eggDrop(int k, int n) {
        // your code here
        memset(dp, -1, sizeof(dp));
        return mcm(k,n);
    }
    
    int dp[10001][101];
    int mcm(int e, int n){
        if(n==0 || n== 1){
            return n;
        }
        if(e == 1){
            return n;
        }
        if(dp[n][e] != -1)return dp[n][e];
        int mini = INT_MAX;
        for(int k = 1;k<=n;k++){
            int steps = 1 + max(mcm(e-1, k-1) , mcm(e, n-k));
            mini = min(steps, mini);
        }
        return dp[n][e] = mini;
    }
};

//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking eggs and floors count
        int n, k;
        cin >> n >> k;
        Solution ob;
        // calling function eggDrop()
        cout << ob.eggDrop(n, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends