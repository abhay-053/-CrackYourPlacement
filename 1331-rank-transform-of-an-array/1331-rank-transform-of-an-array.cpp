class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n == 0){
            return {};
        }

        vector<pair<int,int>> nums;

        for(int i = 0; i < n; i++){
            nums.push_back({arr[i], i});
        }

        sort(begin(nums), end(nums));
        vector<int> ans(n);
        int val = nums[0].first;
        int j = 1;
        for(int i = 0; i<n; i++){
            if(i > 0 && nums[i].first > val){
                val = nums[i].first ;
                j ++;
            }
            ans[nums[i].second] = j;
        }

        return ans;
    }
};