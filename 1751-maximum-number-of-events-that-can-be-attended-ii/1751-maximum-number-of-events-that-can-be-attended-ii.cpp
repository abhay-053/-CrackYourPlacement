class Solution {
public:
    int size, size1;
    vector<vector<int>> dp;
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
        
        if(idx >= events.size() || cnt == 0){
            return 0;
        }

        if(dp[idx][cnt] != -1){
            return dp[idx][cnt];
        }
        
        int k = getNextIdx(events, events[idx][1]);
        int take = events[idx][2] + solve(events, k, cnt - 1);
        int not_take = solve(events, idx + 1, cnt);

        return dp[idx][cnt] = max(take, not_take);


    }
    int maxValue(vector<vector<int>>& events, int k) {
        size = events.size(); 
        size1 = (1e6/size) + (1000006 % size);
        sort(events.begin(), events.end());
        dp.resize(size, vector<int>(size1, -1));
        return solve(events, 0, k);
    }
};