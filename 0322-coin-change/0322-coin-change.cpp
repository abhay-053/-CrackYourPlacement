class Solution {
public:
    int dp[13][10001];
    int find( vector<int> &coins, int idx, int amount)
    {
        if(amount == 0)
        {
            return 0;
        }
        if( idx >= coins.size() || amount < 0)
        {
            return 10001;
        }

        if(dp[idx][amount] != -1)
        {
            return dp[idx][amount];
        }

        int take = 1 + find(coins , idx, amount - coins[idx]);
        int not_take = find(coins, idx+1, amount);

        return dp[idx][amount] = min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        memset(dp, -1, sizeof(dp));
        int res= find(coins, 0, amount);
        return res < 10001 ? res : -1;
    }
};