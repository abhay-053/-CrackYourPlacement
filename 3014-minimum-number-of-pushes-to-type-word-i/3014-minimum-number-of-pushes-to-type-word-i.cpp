class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;
        int cnt = 1;
        while(n>=8){
            n-=8;
            ans += 8 * cnt;
            cnt++;
        }
        ans += n * cnt;
        return ans;
    }
};