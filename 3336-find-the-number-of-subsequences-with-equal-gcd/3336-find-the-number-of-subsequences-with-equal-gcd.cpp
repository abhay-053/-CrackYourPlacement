class Solution {
public:
    static const int MOD = 1e9 + 7;
    int n;
    int dp[201][201][201];
    // int solve(int i, int first, int second, vector<int>& nums){
        
    //     if(i == nums.size()){
    //         int bothTaken = (first != 0 && second != 0);
    //         int isEqual = first == second;

    //         return bothTaken && isEqual;
    //     }

    //     if(dp[i][first][second] != -1 ){
    //         return dp[i][first][second];
    //     }

    //     int skip = solve(i+1, first, second, nums);
    //     int take1 = solve(i+1, gcd(first, nums[i]), second, nums);
    //     int take2 = solve(i+1, first, gcd(second, nums[i]), nums);

    //     return dp[i][first][second] = ((skip + take1) % MOD + take2) % MOD;
    // }
    

    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        // memset(dp, -1, sizeof(dp));
        int maxVal = *max_element(begin(nums), end(nums));
        // int dp[n+1][maxVal + 1][maxVal + 1];
        vector<vector<int>> dp(maxVal+1, vector<int>(maxVal+1));
        for(int i = n; i >= 0; i--){
            vector<vector<int>> ndp(maxVal+1, vector<int>(maxVal+1));
            for(int first = maxVal; first >= 0; first --){
                for(int second = maxVal; second >= 0; second --){

                    if(i == n){
                        if(first != 0 && second != 0 && first == second){
                            dp[first][second] = 1;
                        } else {
                            dp[first][second] = 0;
                        }
                    }
                    else {
                        int skip = dp[first][second];
                        int take1 = dp[__gcd(first, nums[i])][second];
                        int take2 = dp[first][__gcd(second, nums[i])];


                        ndp[first][second] = ((skip + take1) % MOD + take2) % MOD;
                    }
                }
            }
            if( i!= n)
                dp = ndp;
        }
        return dp[0][0];
    }
};