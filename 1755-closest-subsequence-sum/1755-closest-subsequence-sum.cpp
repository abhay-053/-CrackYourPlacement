class Solution {
public:
    vector<int> subsetSum(vector<int>& nums, int start, int n){
        int n1 = n - start;
        vector<int> subsetsum;
        for(int mask = 0; mask <= pow(2, n1) - 1; mask++){
            int sum = 0;
            for(int i = 0; i<n1; i++){
                if(mask & (1<<i)){
                    sum += nums[start + i];
                }
            }
            subsetsum.push_back(sum);
        }
        return subsetsum;
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();

        vector<int> sumA = subsetSum(nums, 0, n/2);
        vector<int> sumB = subsetSum(nums, n/2, n);

        sort(begin(sumB), end(sumB));

        int ans = INT_MAX;
        for(int sum1: sumA){
            int sum2 = goal - sum1;

            int idx = lower_bound(begin(sumB), end(sumB), sum2) - begin(sumB);
            int val1 , val2;

            if(idx < sumB.size()){
                val1 = sum1 + sumB[idx];
                ans = min(ans, abs(val1 - goal));
            }

            if(idx > 0){
                val2 = sum1 + sumB[idx-1];
                ans = min(ans, abs( val2 - goal));
            }
        }

        return ans;
    }
};