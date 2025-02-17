//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int kadane(vector<int> sum, int r){
        int ans = INT_MIN;
        int maxi = 0;
        for(int i=0;i<r;i++){
            maxi += sum[i];
            ans = max(maxi, ans);
            if(maxi<0){
                maxi = 0;
            }
        }
        return ans;
    }
    int maximumSumRectangle(vector<vector<int>> &mat) {
        // code here
        int r = mat.size();
        int c = mat[0].size();
        int res = INT_MIN;
        for(int i=0;i<c;i++){
            vector<int> sum(r, 0);
            for(int j=i;j<c;j++){
                
                for(int row = 0 ; row< r;row++){
                    sum[row] += mat[row][j];
                }
                
                int val = kadane(sum,r);
                
                res = max(val, res);
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(v) << "\n";
    }
}
// } Driver Code Ends