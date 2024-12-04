class Solution {
    public boolean canMakeSubsequence(String str1, String str2) {
        
        
        int len=str1.length();
        int lent=str2.length();
        
        int ind2=0;
        int ind12=0;
        
        int countt=0;
        
        for(int i=0;i<lent;i++){
            
            char c=str2.charAt(i);
            char ori=c;
            if(c=='a'){
                c='z';
            }
            else{
                c--;
            }
            
            while(ind12<len){
                char p=str1.charAt(ind12);
                if(p==c || p==ori){
                    countt++;
                    ind12++;
                    break;
                }else
                    ind12++;
            }
            
        }
        
        if(countt==lent){
            return true;
        }else
            return false;
        
        
    }
}