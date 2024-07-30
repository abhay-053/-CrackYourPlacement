class Solution {
public:
    int minimumDeletions(string s) {
        int ans=0;
        int countB=0;
        for(char c:s){
            if(c=='b'){
                countB++;
            }else{
                ans=min(ans+1,countB);
            }
        }
        return ans;
    }
};