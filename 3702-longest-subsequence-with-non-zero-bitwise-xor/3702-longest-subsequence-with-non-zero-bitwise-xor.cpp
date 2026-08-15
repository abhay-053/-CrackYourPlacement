class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool flag = false;
        int n = nums.size();
        int xr = 0;
        for(int i = 0; i< n; i++){
            xr ^= nums[i];
            if(nums[i] != 0){
                flag = true;
            }
        }

        if(!flag){
            return 0;
        }

        if(xr != 0){
            return n; 
        }
        return n-1;

    }
};