class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int> lastIdx(26, 0);

        for(int i = 0; i < n; i++){
            lastIdx[s[i] - 'a'] = i;
        }

        vector<int> vis(26, 0);
        string str;
        for(int i = 0; i< n; i++){
            char ch = s[i];
            int idx = ch - 'a';
            
            if(vis[idx] == 1){
                continue;
            }
            while(!str.empty() && str.back() > s[i] && lastIdx[str.back() - 'a'] > i){
                vis[str.back() - 'a'] = 0;
                str.pop_back();
            }

            str.push_back(s[i]);
            vis[s[i]-'a'] = 1;

        }
        return str;
    }
};