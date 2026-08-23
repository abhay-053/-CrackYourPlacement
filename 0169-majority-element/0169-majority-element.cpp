class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = 0;
        int n = nums.size();

        int ans = 0;
        for(int i = 0; i< n; i++){
            if(majority == 0){
                ans = nums[i];
                majority += 1;
            } else if(ans == nums[i]){
                majority += 1;
            } else {
                majority -= 1;
            }
        }

        return ans;
    }
};