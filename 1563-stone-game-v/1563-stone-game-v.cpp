class Solution {
public:

    vector<int> prefix;
    int dp[501][501];
    int getSum(int i, int j) {
        if (i == 0)
            return prefix[j];

        return prefix[j] - prefix[i - 1];
    }

    int solve(int i, int j) {
        if (i >= j)
            return 0;

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;
        for (int k = i; k < j; k++) {

            int leftSum = getSum(i, k);
            int rightSum = getSum(k + 1, j);

            if (leftSum < rightSum) {
                ans = max(ans, leftSum + solve(i, k));
            }
            else if (leftSum > rightSum) {
                ans = max(ans,rightSum + solve(k + 1, j));
            }
            else {
                ans = max({ ans,leftSum + solve(i, k), rightSum + solve(k + 1, j)});
            }
        }
        return dp[i][j] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        prefix.resize(n);
        prefix[0] = stoneValue[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stoneValue[i];
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, n - 1);
    }
};