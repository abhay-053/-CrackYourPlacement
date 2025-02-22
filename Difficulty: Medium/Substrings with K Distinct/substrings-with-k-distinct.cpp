//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  int atMostK(string& s, int k) {
    if (k == 0) return 0;
    
    int l = 0, ans = 0;
    unordered_map<char, int> mp;

    for (int r = 0; r < s.size(); r++) {
        mp[s[r]]++;

        while (mp.size() > k) {
            mp[s[l]]--;
            if (mp[s[l]] == 0) {
                mp.erase(s[l]);
            }
            l++;
        }

        ans += (r - l + 1);
    }
    return ans;
}

    int countSubstr(string& s, int k) {
        return atMostK(s,k) - atMostK(s, k-1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.countSubstr(s, k) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends