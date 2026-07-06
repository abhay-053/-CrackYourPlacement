class Solution {
public:
    int dp[100001][3];
    int getNextIdx(vector<vector<int>>& events, int val){
        int l = 0, r= events.size()-1;
        int ans;
        while(l<=r){
            int mid = l + (r-l)/2;

            if(events[mid][0] > val){
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
    int solve(vector<vector<int>>& events, int idx, int cnt){
        
        if(idx >= events.size() || cnt >= 2){
            return 0;
        }

        if(dp[idx][cnt] != -1){
            return dp[idx][cnt];
        }
        
        int k = getNextIdx(events, events[idx][1]);
        int take = events[idx][2] + solve(events, k, cnt + 1);

        int not_take = solve(events, idx + 1, cnt);

        return dp[idx][cnt] = max(take, not_take);


    }
    int maxTwoEvents(vector<vector<int>>& events) {
        memset(dp, -1, sizeof(dp));
        sort(events.begin(), events.end());
        return solve(events, 0, 0);
    }
};