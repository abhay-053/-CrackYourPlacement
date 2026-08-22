class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int prod = 1; 
        int num = n;
        while(n>0){
            int val = n % 10;
            n/= 10;
            sum += val;
            prod *= val;
        }

        if(num % (sum + prod) == 0  ){
            return true;
        }
        return false;
    }
};