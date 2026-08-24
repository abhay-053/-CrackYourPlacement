class Solution {
public:
    int climbStairs(int n) {
        int prevPrev = 1;
        int prev = 2;
        if(n == 1){
            return prevPrev;
        }

        if(n == 2){
            return prev;
        }

        int ways = 0;
        for(int i = 2; i< n; i++){
            ways = prevPrev + prev;
            prevPrev = prev;
            prev = ways;
        }

        return ways;
    }
};