class Solution {
public:
    vector<vector<bool>> isPalindrome;
    vector<int> t;

    int solve(int n, int k) {
        if (n < k) return 0;

        if (t[n] != -1) 
            return t[n];

        int result = solve(n - 1, k); 

        int j = n - 1;
        for (int i = 0; j-i+1>=k; i++) {
            if (isPalindrome[i][j]) {
                result = max(result, 1 + solve(i, k));
            }
        }

        return t[n] = result;
    }

    int maxPalindromes(string s, int k) {
        int n = s.length();
        isPalindrome.assign(n, vector<bool>(n, false));

        for (int L = 1; L <= n; L++) {
            for (int i = 0; i + L <= n; i++) {
                int j = i + L - 1;

                if (i == j) {
                    isPalindrome[i][i] = true;
                } else if (i + 1 == j) {
                    isPalindrome[i][j] = (s[i] == s[j]);
                } else {
                    isPalindrome[i][j] = ((s[i] == s[j]) && isPalindrome[i+1][j-1] == true);
                }
            }
        }

        t.assign(n + 1, -1);
        return solve(n, k);
    }
};