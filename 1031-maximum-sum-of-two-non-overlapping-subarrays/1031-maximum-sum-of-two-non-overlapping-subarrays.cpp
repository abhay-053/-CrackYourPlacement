class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> prefix(n+1, 0);
        for(int i = 1; i<= n; i++){
            prefix[i] = prefix[i-1] + nums[i-1];
        }

        int maxSum = 0;
        for(int i = firstLen ; i <= n; i++){
            int sum = prefix[i] - prefix[i - firstLen];
            int sum1 = 0;
        
            if(i + secondLen <= n){
                for(int j = i + secondLen; j <= n; j++){
                    sum1 = max(sum1, prefix[j] - prefix[j-secondLen]);
                }
            }

            if(i >= firstLen + secondLen){
                for(int j = secondLen; j < i - firstLen; j++){
                    sum1 = max(sum1, prefix[j] - prefix[j-secondLen]);
                }
            }

            maxSum = max(maxSum, sum + sum1);
        }
        return maxSum;
    }
};