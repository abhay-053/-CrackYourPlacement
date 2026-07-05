class Solution {
public:
    // int dp[1001][1001];
    // int solve(string &s, int i, int j){
    //     if(i>=j){
    //         return 1;
    //     }

    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     if(s[i] == s[j] ){
    //         return dp[i][j] = solve(s, i+1, j-1);
    //     } 
    //     return dp[i][j] = 0;
    // }
    string longestPalindrome(string s) {
        int idx = 0, maxL = INT_MIN;
        int n = s.size(); 
        // memset(dp, -1, sizeof(dp));
        // for(int i = 0; i< n;i++){
        //     for(int j = i; j< n; j++){
        //         if(solve(s, i, j) == true){
        //             if(j-i+1 > maxL){
        //                 maxL = max(maxL, j-i+1);
        //                 idx = i;
        //             }
        //         }
        //     }
        // }

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int i = 0 ; i< n; i++){
            dp[i][i] = 1;
            maxL = 1;
        }

        for(int k = 2; k<=n; k++){
            for(int i = 0; i<n-k+1 ; i++){
                int j = i + k - 1; 
                if(s[i] == s[j] && k==2){
                    dp[i][j] = 1; 
                    maxL = 2; 
                    idx = i;
                } else if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = 1; 
                    if(maxL < j-i+1){
                        maxL = j-i+1;
                        idx = i;
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return s.substr(idx, maxL);
    }
};