class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int> diff(2 * limit + 2, 0);


        int n = nums.size();
        for(int i = 0; i*2<n; i++){
            int a = nums[i];
            int b = nums[n-i-1];

            int minSum = min(a,b) + 1;
            int maxSum = max(a, b) + limit;

            //assume all required two operation which is max operation required to make sum 
            diff[2] += 2;
            diff[2*limit + 1] += (-2);

            //now minSum and maxSum are achievable in 1 operation so subtract 1 with all range[minSum, maxSum]

            diff[minSum] += (-1);
            diff[maxSum + 1] += 1;

            //now if want to arr[i] + arr[n-i-1] as sum that will achievale in 0 moves so again subract 1 with all arr[i]  + arr[n-i-1]

            diff[a+b] += (-1);
            diff[a+b+1] += 1;
        }

        int result = INT_MAX;

        for(int i = 3; i <2*limit+1; i++){
            diff[i] += diff[i-1];
            
        }

        for(int i = 2; i<2*limit+1; i++){
            result = min(result, diff[i]);
        }

        return result;
    }
};