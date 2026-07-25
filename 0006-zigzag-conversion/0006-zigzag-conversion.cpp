class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();

        if(numRows == 1){
            return s;
        }
        vector<string> arr(numRows);

        int i = 0;
        int dir = 0;
        int k = 0;
        while(k < n){
            arr[i] += s[k++];

            if(i == 0){
                dir = 0;
            } else if(i == numRows - 1){
                dir = 1;
            }

            if(dir == 0){
                i++;
            } else {
                i--;
            }
        }
        string str;
        for(auto i: arr){
            str += i;
        }
        return str;
    }
};