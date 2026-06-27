class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> mp;
        for(auto &i: nums){
            mp[i]++;
        }
        int res = 0;
        if(mp[1] % 2){
            res = mp[1];
        } else {
            res = mp[1] - 1;
        }
        long long cur ;
        for(auto [num, _]: mp){
            if(num == 1){
                continue;
            }
            cur = 1ll*num;
            int len = 0;
            while(mp.count(cur) && mp[cur] > 1){
                len += 2;
                cur = cur * cur;
            }

            if(mp.count(cur) == 1){
                len += 1;
            } else {
                len -= 1;
            }

            res = max(res, len);
        }

        return res;
    }
};