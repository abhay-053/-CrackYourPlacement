class Solution {
public:

    int MOD = 1e9+7;
    int dp[2001];
    vector<int> prev;
    int solve(int n ){
        if(n== 0){
            return 1;

        }
        if(dp[n] != -1){
            return dp[n];
        }
        int total = (2*1ll*solve(n-1)) % MOD;
        int dup = 0;
        if(prev[n] != 0){
            dup = solve(prev[n] - 1);
            total = (total - dup + MOD) % MOD;
        }
        return dp[n] = total;


    }
    int distinctSubseqII(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));

        prev.assign(n+1, 0);

        vector<int> lastSeen(26,0);

        for(int i = 1; i<= n; i++){
            int idx = s[i-1] - 'a';
            prev[i] = lastSeen[idx];
            lastSeen[idx] = i;
        }

        return (solve(n) - 1 + MOD ) % MOD;
    }
};

 