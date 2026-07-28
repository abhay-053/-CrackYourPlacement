class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int> mp;
        for(auto ch: s){
            mp[ch]++;
        }

        string str="";
        bool isOdd = false;
        char tmp;
        for(auto itr: mp){
            char ch = itr.first;
            int freq = itr.second;

            if(freq % 2){
                isOdd = true;
                tmp = ch;
                freq -= 1;
            }
            while(freq > 0){
                freq -=2;
                str += ch;
            }
        }

        string str1 = str;
        reverse(begin(str1), end(str1));
        if(isOdd){
            str += tmp;
        }
        str += str1;
        return str;
        
    }
};