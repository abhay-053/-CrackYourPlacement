class Solution {
public:
    bool isPossible(long long strength, vector<long long>& boosts, vector<int>& monsters){
        int n = monsters.size();
        long long curStrength = strength;
        for(int i = 0; i< n; i++){
            if(curStrength + boosts[i] >= monsters[i]){
                curStrength -= monsters[i];
                if(curStrength < 0){
                    curStrength = 0;
                }
            } else {
                return false;
            }
        }
        return true;
    }
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        long long ans = 0;
        int n = monsters.size();

        vector<long long> nums(n+1, 0);
        for(auto i: boosts){
            int l = i[0];
            int r = i[1];
            int val = i[2];

            nums[l] += val;
            nums[r+1] += -val;
        }

        for(int i = 1; i<= n; i++){
            nums[i] += nums[i-1];
        }

        nums.pop_back();
        long long l = 0; 
        long long r = accumulate(begin(monsters), end(monsters), 0ll);
        while(l<=r){
            long long mid = l + (r - l)/2;

            if(isPossible(mid, nums, monsters)){
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return ans;
    }
};