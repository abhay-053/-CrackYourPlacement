class Solution {
public:
    int helper(vector<int>& days, vector<int>& costs, int idx , int dp[])
    {
        if(idx>= days.size())
        {
            return  0;
        }

        if(dp[idx]!= -1)
            return dp[idx];
        int cost_1= costs[0] + helper(days,costs,idx+1,dp);
        int i = 0;
        int maxDay = days[idx]+7;
        int idx1= idx;
        while(idx1 < days.size() && days[idx1] < maxDay)
        {
            idx1++;
        }
        int cost_7= costs[1] + helper(days,costs,idx1,dp);

        maxDay = days[idx] + 30;
        idx1 = idx;
        while( idx1 < days.size() && days[idx1] < maxDay)
        {
            idx1++;
        }
        int cost_15 = costs[2] + helper(days,costs,idx1,dp);

        return dp[idx] = min({cost_1,cost_7,cost_15});

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int dp[366] ;
        memset(dp,-1,sizeof(dp));
        return helper(days,costs,0,dp);
    }
};