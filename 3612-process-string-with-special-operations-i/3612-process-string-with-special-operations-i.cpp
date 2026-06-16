class Solution {
public:
    string processStr(string s) {
        string res = "";

        int n = s.size();

        for(int i = 0; i < n; i++){
            if(s[i] == '#'){
                res += res;
            } else if(s[i] == '%'){
                reverse(begin(res), end(res));
            } else if(s[i] == '*'){
                if(res.size() > 0){
                    res.pop_back();
                }
            } else {
                res += s[i];
            }
        }
        return res;
    }
};