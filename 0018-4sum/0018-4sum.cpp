class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        int n = nums.size();
        long val;
        for(int i = 0; i< n; i++){
            for(int j = i+1; j < n; j++){
                int k = j+1, l = n-1;

                while(k < l){
                    val = 1ll*nums[i] + 1ll*nums[j] + 1ll*nums[k] + 1ll*nums[l];
                    if(val == 1ll*target){
                        st.insert({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                    } else if( val < target){
                        k++;
                    } else {
                        l--;
                    }
                }

            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};