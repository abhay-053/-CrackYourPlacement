class Solution {
public:

    int dp[101];
    int decode(string s, int i){
        if(i == s.size()){
            return 1;
        }

        if(s[i] == '0'){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }
        int ways = decode(s, i+1);

        if(i + 1 < s.size()){
            int num = (s[i] - '0') * 10 + (s[i+1] - '0');

            if(num >= 10 && num <= 26){
                ways += decode(s, i+2);
            }
        }

        return dp[i] = ways;
    }
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return decode(s, 0);
    }
};