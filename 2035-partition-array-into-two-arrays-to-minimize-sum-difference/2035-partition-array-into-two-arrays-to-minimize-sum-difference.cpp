class Solution {
public:
    void solve(int n1, int n, vector<int>& nums, unordered_map<int, vector<int>> &subsetSum) {

        for(int mask = 0; mask < (1<<n); mask++){
            int sum = 0; 
            int count = 0;
            for(int i = 0; i< n; i++){
                if(mask & (1<<i)){
                    sum += nums[i + n1];
                    count++;
                }
            }

            subsetSum[count].push_back(sum);
        }
    }
    int minimumDifference(vector<int>& nums) {
        int N = nums.size();

        int n1 = N/2;
        unordered_map<int, vector<int>> leftSum, rightSum;
        int sum = accumulate(begin(nums), end(nums), 0);
        solve(0, n1, nums, leftSum);
        solve(n1 , n1, nums, rightSum);

        for(auto &rSum: rightSum){
            sort(begin(rSum.second), end(rSum.second));
        }


        int ans = INT_MAX;
        for(auto lSum : leftSum){
            int size = lSum.first;
            vector<int> left = lSum.second;

            int neededSize = n1 - size;
            vector<int> right = rightSum[neededSize];

            for(auto &val: left){
                int target = (sum / 2) - val;
                int idx = lower_bound(begin(right), end(right), target) - begin(right);

                if (idx < right.size()) {
                    ans = min( ans, abs(2 * (val + right[idx]) - sum));
                }

                if (idx > 0) {
                    ans = min( ans, abs(2 * (val + right[idx - 1]) - sum));
                }
            }
            
            
        }
        return ans;
    }
};