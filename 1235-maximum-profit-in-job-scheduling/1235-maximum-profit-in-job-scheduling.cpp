class Solution {
public:

    int dp[50002];
    int getNextIdx(vector<vector<int>>& events, int val){
        int l = 0, r= events.size()-1;
        int ans;
        while(l<=r){
            int mid = l + (r-l)/2;

            if(events[mid][0] >= val){
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
    int solve(vector<vector<int>>& events, int idx){
        
        if(idx >= events.size() ){
            return 0;
        }

        if(dp[idx]!= -1){
            return dp[idx];
        }
        
        int k = getNextIdx(events, events[idx][1]);
        int take = events[idx][2] + solve(events, k);

        int not_take = solve(events, idx + 1);

        return dp[idx] = max(take, not_take);


    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> events(n, vector<int>(3));

        for(int i = 0; i< n; i++){
            events[i][0] = startTime[i];
            events[i][1] = endTime[i];
            events[i][2] = profit[i];
        }

        sort(events.begin(), events.end());

        memset(dp, -1, sizeof(dp));

        return solve(events, 0);
    }
};