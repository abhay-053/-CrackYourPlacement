class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto i: nums){
            mp[i]++;
        }   
        int n = nums.size();

        vector<vector<int>> bucket(n+1);

        for(auto &[key, freq]: mp){
            bucket[freq].push_back(key);
        }

        vector<int> ans;
        for(int i = n ; i >= 1; i--){
            for(int num: bucket[i]){
                ans.push_back(num);
                if(ans.size() == k){
                    return ans;
                }
            }
        }
        return {};
    }
};