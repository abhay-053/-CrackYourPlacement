class Solution {
public:
    int solve(vector<int> &nums, int i, int j){
        if(i > j){
            return 0;
        }
        return max(nums[i] + min(solve(nums, i+1, j-1), solve(nums, i+2, j)), nums[j] + min(solve(nums, i+1, j-1), solve(nums, i, j - 2)) );
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int player1 = solve(nums, 0, n-1);
        int totalSum = accumulate(begin(nums), end(nums), 0);
        int player2 = totalSum - player1;
        return player1 >= player2;
    }
};