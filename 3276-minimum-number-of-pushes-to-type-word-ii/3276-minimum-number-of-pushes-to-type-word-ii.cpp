class Solution {
public:
    int minimumPushes(string word) 
    {
        vector<pair<int, char>> vp;
        vector<int> v(26);

        for (auto i : word) {
            v[i - 'a']++;
        }

        sort(v.rbegin(), v.rend());
        int n = v.size();
        int ans = 0;
        int i = 0;
        int count = 1;

        while (i < v.size() && n > 0) 
        {
            ans += accumulate(v.begin() + i, v.begin() + i + min(8, n), 0) * count;
            count++;
            i += 8;
            n -= 8;
        }

        return ans;
    }
};
