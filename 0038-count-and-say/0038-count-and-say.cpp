class Solution {
public:
    string countAndSay(int n) {
        if( n == 1){
            return "1";
        }

        string say = countAndSay(n-1);

        string res = "";

        for(int i = 0; i < say.size() ; i++){
            int cnt = 1;
            char ch = say[i];
            while(i < say.size() - 1 && say[i] == say[i+1]){
                cnt++;
                i++;
            }

            res += to_string(cnt) + ch;
        }

        return res;
    }
};