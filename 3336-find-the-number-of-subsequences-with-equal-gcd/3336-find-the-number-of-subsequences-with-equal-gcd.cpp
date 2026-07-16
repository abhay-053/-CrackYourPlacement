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
        int dp[n+1][maxVal +1][maxVal + 1];
        for(int first = 0; first <= maxVal ; first ++){
            for(int second = 0; second <= maxVal; second ++){
                if(first != 0 && second != 0 && first == second){
                    dp[n][first][second] = 1;
                } else {
                    dp[n][first][second] = 0;
                }
            }
        }

        for(int i = n-1; i >= 0; i--){
            for(int first = maxVal; first >= 0; first --){
                for(int second = maxVal; second >= 0; second --){

                    int skip = dp[i+1][first][second];
                    int take1 = dp[i+1][__gcd(first, nums[i])][second];
                    int take2 = dp[i+1][first][__gcd(second, nums[i])];

                    dp[i][first][second] = ((skip + take1) % MOD + take2) % MOD;
                }
            }
        }
        return dp[0][0][0];
    }
};