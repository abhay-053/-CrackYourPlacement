class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        if(nums.empty()){
            return {};
        }
        int n = nums.size();
        vector<int> ans;
        int base = *min_element(begin(nums), end(nums));
        int last = *max_element(begin(nums), end(nums));
        int range = last - base + 1;
        vector<bool> arr(range, 0);
        for(int i = 0; i < n; i++){
           arr[nums[i] - base] = 1;
        }

        for(int i = 0; i< range; i++){
            if(arr[i] == 0){
                ans.push_back(i + base);
            }
        }
        return ans;
    }
};