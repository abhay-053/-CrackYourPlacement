//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    double waterOverflow(int K, int R, int C) {
        // code here
        vector<vector<double>> arr(R + 1, vector<double>(R + 1, 0.0));
        arr[0][0] = K;
    
        for (int i = 0; i < R; i++) {
            for (int j = 0; j <= i; j++) {
                if (arr[i][j] > 1.0) {
                    double excess = arr[i][j] - 1.0;
                    arr[i][j] = 1.0;
                    arr[i + 1][j] += excess / 2.0;
                    arr[i + 1][j + 1] += excess / 2.0;
                }
            }
        }
    
        return min(1.0, arr[R - 1][C - 1]);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int K,R,C;
        
        cin>>K>>R>>C;

        Solution ob;
        cout << fixed << setprecision(6)<< ob.waterOverflow(K,R,C) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends