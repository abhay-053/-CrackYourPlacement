class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int cIdx = -1;
        int maxIdx = -1; 
        int minIdx = -1;
        int n = nums.size();
        long long ans = 0;
        for(int i = 0; i< n; i++){
            if(nums[i] < minK || nums[i] > maxK){
                cIdx = i;
            }

            if(nums[i] == minK){
                minIdx = i;
            }

            if(nums[i] == maxK){
                maxIdx = i;
            }

            int smallIdx = min(maxIdx, minIdx);

            int tmp = smallIdx - cIdx;
            ans += (tmp <= 0) ? 0 : tmp;
        }
        return ans;
    }
};