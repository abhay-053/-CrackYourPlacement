class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd;

        int mxi = 0;
        for(auto &i: nums){
            mxi = max(mxi, i);
            prefixGcd.push_back(gcd(i, mxi));
        }

        long long sum = 0;
        sort(begin(prefixGcd), end(prefixGcd));
        for(int i = 0; i< n/2; i++){
            sum += gcd(prefixGcd[i] , prefixGcd[n-1-i]);
        }

        return sum;
    }
};