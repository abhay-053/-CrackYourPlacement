class Solution {
public:
    char processStr(string s, long long k) {
        long long l = 0;

        for(char &ch: s){
            if(ch == '*'){
                if(l> 0)
                    l--;
            } else if(ch == '%'){
                continue;
            } else if(ch == '#'){
                l *= 2ll;
            } else {
                l++;
            }
        }

        if(k >= l){
            return '.';
        }

        int n = s.size();
        for(int i = n - 1; i>=0; i--){
            char ch = s[i];
            if(ch == '*'){
                l++;
            } else if(ch == '%'){
                k = l - k - 1;
            } else if(ch == '#'){
                l = l/2;

                if(k >= l){
                    k = k-l;
                }
            } else {
                l--;
            }

            if(l == k){
                return ch;
            }
        }

        return '.';
    }
};