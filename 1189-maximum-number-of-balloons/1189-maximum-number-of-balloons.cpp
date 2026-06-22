class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;

        for(auto &ch: text){
            mp[ch]++;
        }

        int cnt = min(mp['b'], min(mp['a'], mp['n']));
        cnt = min(cnt, min(mp['l']/2, mp['o']/2));

        return cnt;
    }
};