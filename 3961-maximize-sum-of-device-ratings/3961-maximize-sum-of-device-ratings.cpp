class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        long long ans = 0;
        if(units[0].size() == 1){
            for(int i = 0; i< units.size(); i++){
                ans += units[i][0];
            }
            return ans;
        }

        for(int i = 0; i< units.size(); i++){
            sort(units[i].begin(), units[i].end());
        }

        int mini = INT_MAX, mini1 = INT_MAX;
        vector<int> arr;
        for(int  i = 0; i< units.size(); i++){
            ans += units[i][1];
            mini1 = min(mini1, units[i][1]);
            mini = min(mini, units[i][0]);
        }

        ans =  ans - mini1 + mini;
        return ans;
    }
};