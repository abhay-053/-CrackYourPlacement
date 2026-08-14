class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 0;
        int l = 0;
        int n = s.size();
        vector<int> mp(26, 0);
        for(int i = 0; i< n; i++){
            int ch = s[i] - 'a';
            mp[ch]++;

            while(mp[ch] > 2){
                mp[s[l]-'a']--;
                l++;
            }

            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};