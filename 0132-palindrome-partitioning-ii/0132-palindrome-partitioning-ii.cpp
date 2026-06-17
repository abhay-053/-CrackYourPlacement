class Solution {
public:
    int dp[2001];
    vector<vector<int>> palindrome;
    bool isPalindrome(int i, int j, string &s){
        if(palindrome[i][j] != -1){
            return palindrome[i][j];
        }

        while(i<j){
            if(s[i] != s[j]){
                return palindrome[i][j] = false;
            }
            i++;
            j--;
        }
        return palindrome[i][j] = true;
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
        int n = s.size();
        palindrome.resize(n, vector<int>(n,-1));
        return solve(0, s.size() -1, s);
    }
};