class Solution {
public:
    int dp[501][501];
    int solve(vector<int> &nums, int i, int j){
        if(i > j){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        return dp[i][j] = max(nums[i] + min(solve(nums, i+1, j-1), solve(nums, i+2, j)), nums[j] + min(solve(nums, i+1, j-1), solve(nums, i, j - 2)) );
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(dp, -1, sizeof(dp));
        int player1 = solve(piles, 0, n-1);
        int totalSum = accumulate(begin(piles), end(piles), 0);
        int player2 = totalSum - player1;
        return player1 > player2;
    }
};

