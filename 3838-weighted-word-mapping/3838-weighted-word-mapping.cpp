class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int k = 0; 
        int val ;
        string ans = "";
        for(auto str: words){
            val = 0;
            int i ;
            for(i = 0; i< str.size(); i++){
                val += weights[str[i] - 'a'] ;
            }
            k = i;
            val = val % 26;
            val = 25 - val;

            ans += 'a' + val;
        }
        return ans;
    }
};