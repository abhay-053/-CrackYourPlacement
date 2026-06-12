class Solution {
public:
    string num ;
    int dp[12][2][2];
    int countNum(int idx, int tight, int started, vector<string>& digits){
        if(idx == num.size()){
            return started;
        }

        if(dp[idx][tight][started] != -1){
            return dp[idx][tight][started];
        }
        long long ans = 0;

        if(!started){
            ans += countNum(idx + 1, tight & (0 == num[idx] -'0'), 0, digits);
        }

        int limit = tight == 1? num[idx] - '0': 9;
        for(string &str: digits){
            int nm = str[0] - '0';
            if(limit < nm){
                continue;
            }

            ans += countNum(idx + 1, tight & (nm == limit), 1, digits);
        }

        return dp[idx][tight][started] = ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        num = to_string(n);
        memset(dp, -1, sizeof(dp));

        return countNum(0, 1, 0, digits);
    }
};