class Solution {
public:
    int maxProduct(int n) {
        int max_1 = 0, max_2 = 0;

        while(n>0){
            int num = n%10;
            if(max_1 < num){
                max_2 = max_1;
                max_1 = num;
            } else if(max_2 < num){
                max_2 = num;
            }
            n/=10;
        }

        return max_1 * max_2;
    }
};