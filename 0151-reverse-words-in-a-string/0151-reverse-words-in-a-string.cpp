class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        int n = s.size();
        int ends = 0;
        string str ="";
        int i = 0;
        while(i < n){
    
            if(s[i] == ' '){
                while( i < n && s[i] == ' '){
                    i++;
                }
                start = i;
            }

            while( i < n && s[i] != ' '){
                i++;
                ends = i;
            }

            if(start != -1 && ends != -1){
                reverse(s.begin() + start , s.begin() + ends);
                str += s.substr(start, ends - start) + ' ';
            }

            start = -1 ;
            ends = -1;
            cout<<str;
        }
        str.pop_back();
        reverse(str.begin(), str.end());
        return str;
    }
};