class Solution {
public:
    long long sumAndMultiply(int n) {
        int x = 0;
        int sum = 0;
        while(n>0){
            if(n%10 != 0)
                x = x*10 + n%10;
            
            sum+= n%10;
            n/=10;
        }
        int num1 = 0;
        while(x >0){
            num1 = num1*10 + x%10;
            x/=10;
        }
        return num1*1ll*sum;
    }
};