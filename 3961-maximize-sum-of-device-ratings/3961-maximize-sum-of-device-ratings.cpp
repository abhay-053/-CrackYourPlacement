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

        int mini = INT_MAX;
        vector<int> arr;
        for(int  i = 0; i< units.size(); i++){
            arr.push_back(max(units[i][0], units[i][1]));
            mini = min(mini, min(units[i][0] , units[i][1]));
        }

        sort(arr.begin(), arr.end());
        ans = mini;
        for(int i = 1; i< arr.size(); i++){
            ans += 1ll *arr[i];
        }
        return ans;
    }
};