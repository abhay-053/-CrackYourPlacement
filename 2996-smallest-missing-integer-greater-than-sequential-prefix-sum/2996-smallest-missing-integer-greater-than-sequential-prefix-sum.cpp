class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        int n = nums.size();
        int maxSum = 0;
        for(int i = 1; i< n; i++){
            if(nums[i] == nums[i-1] + 1){
                sum += nums[i];
            } else{
                maxSum = max(sum, maxSum);
                break;                
            }
        }
        maxSum = max(sum, maxSum);
        unordered_set<int> st(nums.begin(), nums.end());
        while(1){
            if(st.find(maxSum) == st.end()){
                return maxSum;
            } else {
                maxSum++;
            }
        }
        return 0;
        
    }
};