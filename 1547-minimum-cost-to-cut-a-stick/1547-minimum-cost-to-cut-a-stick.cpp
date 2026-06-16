class Solution {
public:
    vector<int> cut;
    int dp[103][103];
    int cutStick(int l, int r){

        if(r  - l < 2){
            return 0;
        }

        if(dp[l][r] != -1){
            return dp[l][r];
        }
        int res = INT_MAX;
        for(int k = l + 1; k <= r-1; k++){
            int cost = (cut[r] - cut[l]) + cutStick(l, k) + cutStick(k, r);

            res = min(res, cost);
        }

        return dp[l][r] = res;
    }
    int minCost(int n, vector<int>& cuts) {
        memset(dp, -1, sizeof(dp));
        sort(cuts.begin(), cuts.end());
        cut = cuts;
        cut.push_back(n);
        cut.insert(cut.begin(), 0);
        return cutStick(0, cut.size() - 1);
    }
};