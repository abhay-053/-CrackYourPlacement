class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int mini = INT_MAX, maxi = INT_MIN;
        for(auto i: prices)
        {
            mini = min(mini, i);
            maxi = max(maxi, i-mini);
        }
        return maxi;
    }
};