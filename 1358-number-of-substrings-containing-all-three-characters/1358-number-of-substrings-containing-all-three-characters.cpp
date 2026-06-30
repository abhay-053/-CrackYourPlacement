class Solution {
public:
    int numberOfSubstrings(string s) {
        int cntA = 0, cntB = 0, cntC = 0;
        int subString = 0;
        int n = s.size(); 
        int l = 0;
        for(int i = 0;  i < n; i++){
            if(s[i] == 'a'){
                cntA++;
            } else if(s[i] == 'b'){
                cntB++;
            } else if(s[i] == 'c'){
                cntC++;
            }

            while(cntA > 0 && cntB > 0 && cntC > 0){
                if(s[l] == 'a'){
                    cntA--;
                } else if(s[l] == 'b'){
                    cntB--;
                } else if(s[l] == 'c'){
                    cntC--;
                }

                subString += n - i;
                l++;
            }
        }
        return subString;
    }
};