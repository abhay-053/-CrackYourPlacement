class Solution {
public:
    static const int MOD = 1e9 + 7;
    int n;
    int dp[201][201][201];
    int solve(int i, int first, int second, vector<int>& nums){
        
        if(i == nums.size()){
            int bothTaken = (first != 0 && second != 0);
            int isEqual = first == second;

            return bothTaken && isEqual;
        }

        if(dp[i][first][second] != -1 ){
            return dp[i][first][second];
        }

        int skip = solve(i+1, first, second, nums);
        int take1 = solve(i+1, gcd(first, nums[i]), second, nums);
        int take2 = solve(i+1, first, gcd(second, nums[i]), nums);

        return dp[i][first][second] = ((skip + take1) % MOD + take2) % MOD;
    }
    

    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, nums);
    }
};