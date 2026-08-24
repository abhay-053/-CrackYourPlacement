class Solution {
public:
    string removeKdigits(string num, int k) {

        if(k >= num.size())
            return "0";

        string st;

        for(char ch : num) {

            while(!st.empty() && st.back() > ch && k > 0) {
                st.pop_back();
                k--;
            }

            st.push_back(ch);
        }

        while(k > 0) {
            st.pop_back();
            k--;
        }

        int i = 0;
        while(i < st.size() && st[i] == '0') {
            i++;
        }

        string ans = st.substr(i);

        if(ans.empty())
            return "0";

        return ans;
    }
};