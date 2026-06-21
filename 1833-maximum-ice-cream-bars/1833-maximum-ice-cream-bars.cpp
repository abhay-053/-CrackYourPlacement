class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int iceCream = 0;
        for(auto &i: costs){
            coins -= i;
            if(coins < 0){
                break;
            }
            iceCream ++;
        }
        return iceCream;
    }
};