class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> mp(26,0);
        int n = s.size();
        for(auto ch: s){
            mp[ch-'a']++;
        }

        int idx = 0;
        string str(n, ' ');
        bool isOdd = false;
        char tmp;
        int i = 0;
        for(auto itr = 0; itr < 26; itr++ ){
            char ch = itr + 'a';
            int freq = mp[itr];

            if(freq % 2){
                isOdd = true;
                tmp = ch;
                freq -= 1;
            }
            while(freq > 0){
                freq -=2;
                str[i++] = ch;
            }
        }

        if(isOdd){
            str[i++] = tmp;
        }

        for(i = 0; i< n/2; i++){
            str[n-i-1] = str[i]; 
        }
        return str;
        
    }
};