class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int cost = 0;
        int n = s.size();
        int cnt = 0;
        int left = 0;
        for(int i = 0; i < n; i++){
            cost += abs(s[i] - t[i]);

            while(cost > maxCost){
                cost -= abs(s[left] - t[left]);
                left++;
            }

            cnt = max(cnt, i - left + 1);
        }
        return cnt;
    }
};