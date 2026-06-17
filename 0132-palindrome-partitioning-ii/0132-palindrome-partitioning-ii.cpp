class Solution {
public:
    int dp[2001];
    bool isPalindrome(int i, int j, string &s){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(int i, int j, string &s){
        if(i>= j || isPalindrome(i, j, s)){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int ans = INT_MAX;
        for(int k = i; k<j ; k++){
            if(isPalindrome(i,k, s)){
                int part = 1 + solve(k+1, j, s);
                ans = min(ans, part);
            }
        }

        return dp[i]= ans;
    }
    int minCut(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(0, s.size() -1, s);
    }
};