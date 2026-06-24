class Solution {
public:
    int MOD = 1e9+7;
    typedef long long ll;
    int N, M;
    // int solve(int i, int prevVal, int increasing){
    //     if(i == N){
    //         return 1;
    //     }

    //     if(dp[i][prevVal][increasing] != -1){
    //         return dp[i][prevVal][increasing];
    //     }

    //     ll ans = 0;

    //     if(increasing){
    //         for(int startVal = prevVal + 1; startVal <= M; startVal++){
    //             ans = (ans + solve(i + 1, startVal, false)) % MOD;
    //         }
    //     } else {
    //         for(int startVal = 1; startVal < prevVal; startVal++){
    //             ans = (ans + solve(i + 1, startVal, true)) % MOD;
    //         }
    //     }

    //     return dp[i][prevVal][increasing] = ans;
    // }
    int zigZagArrays(int n, int l, int r) {
        N = n; 
        M = r - l + 1;
        ll res = 0;

        ll dp[2001][2001][2];
        for(int prevVal = 1; prevVal <= M; prevVal ++){
            dp[N][prevVal][0] = 1;
            dp[N][prevVal][1] = 1;
        }
        for(int i = N-1; i>=0; i--){
            vector<ll> curr0(M + 1, 0);
            vector<ll> curr1(M + 1, 0);

            for(int prevVal = 1; prevVal<= M; prevVal++){
                curr0[prevVal] = (curr0[prevVal-1] + dp[i+1][prevVal][0]) % MOD;
                curr1[prevVal] = (curr1[prevVal-1] + dp[i+1][prevVal][1]) % MOD;

            }
            for(int prevVal = 1; prevVal <= M; prevVal++){
                
                // for(int nextVal = prevVal + 1; nextVal <= M; nextVal ++){
                //     dp[i][prevVal][1] = (dp[i][prevVal][1] + dp[i + 1][nextVal][0]) % MOD;
                // }
                dp[i][prevVal][1] = (curr0[M] - curr0[prevVal] + MOD) % MOD;
                // for(int nextVal = 1; nextVal < prevVal; nextVal ++){
                //     dp[i][prevVal][0] = (dp[i][prevVal][0] + dp[i + 1][nextVal][1]) % MOD;
                // }
                dp[i][prevVal][0] = curr1[prevVal - 1];
            }
            
        }
        for(int startVal = 1; startVal <= M; startVal++){

            //increasing

            // res = (res + solve(1, startVal, true) )% MOD;
            res = (res + dp[1][startVal][1]) % MOD;

            // decreasing

            // res = (res + solve(1, startVal, false)) % MOD;
            res = (res + dp[1][startVal][0]) % MOD;
        }   

        return res;
        
    }
};

