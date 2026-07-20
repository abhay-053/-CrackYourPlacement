class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<int> lastIdx(26, 0);

        for(int i = 0; i < n; i++){
            lastIdx[s[i] - 'a'] = i;
        }

        vector<int> vis(26, 0);
        stack<char> st;
        for(int i = 0; i< n; i++){

            char ch = s[i];

            int idx = ch - 'a';
            
            if(vis[idx] == 1){
                continue;
            }
            while(!st.empty() && st.top() > s[i]){

                if(lastIdx[st.top()-'a'] > i){
                    vis[st.top() - 'a'] = 0;
                    st.pop();
                } else {
                    break;
                }
            }

            st.push(s[i]);
            vis[s[i]-'a'] = 1;

        }

        string str;
        while(!st.empty()){
            str += st.top();
            st.pop();
        }

        reverse(str.begin(), str.end());
        return str;
    }
};