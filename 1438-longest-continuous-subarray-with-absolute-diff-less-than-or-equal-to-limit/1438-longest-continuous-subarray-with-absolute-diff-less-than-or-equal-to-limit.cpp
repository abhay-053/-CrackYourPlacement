class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> minDq, maxDq;

        int n = nums.size();
        int left = 0;
        int ans = 0;
        for(int i = 0; i< n; i++){
            while(!maxDq.empty() && nums[maxDq.back()] < nums[i]){
                maxDq.pop_back();
            }

            maxDq.push_back(i);
       
            while(!minDq.empty() && nums[minDq.back()] > nums[i]){
                minDq.pop_back();
            }

            minDq.push_back(i);

            while(nums[maxDq.front()] - nums[minDq.front()] > limit){
                if(maxDq.front() == left){
                    maxDq.pop_front();
                }

                if(minDq.front() == left){
                    minDq.pop_front();
                }

                left++;
            }

            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};