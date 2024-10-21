class Solution {
public:
    int ans=0;
    void solve(string s, int index,unordered_set<string> st){
        if(index>=s.length()) {
            ans=ans<st.size()?st.size():ans;
            return ;
        }
        
        string temp;

        for(int i=index;i<s.length();i++){
            temp+=s[i];
            if(st.find(temp)==st.end())
            {
                st.insert(temp);
                solve(s,i+1,st);
                st.erase(temp);
            }
        }

    }
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        solve(s,0,st);
        return ans;
    }
};