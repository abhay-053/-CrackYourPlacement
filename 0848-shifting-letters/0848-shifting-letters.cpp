class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        int rotation = 0;
        string res;
        for(int i = n - 1; i>= 0; i--){
            rotation += shifts[i];
            rotation %= 26;

            res += ((s[i] - 'a' + rotation) % 26) + 'a';
        }
        reverse(begin(res), end(res));
        return res;
    }
};