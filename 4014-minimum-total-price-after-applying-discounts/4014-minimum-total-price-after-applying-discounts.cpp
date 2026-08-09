class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(rbegin(prices), rend(prices));
        sort(rbegin(discounts), rend(discounts));
        double price = 0;
        int n = prices.size();
        int m = discounts.size();
        int i;
        for(i = 0; i < min(n, m); i++){
            price += (prices[i] * (100 - discounts[i]))/100.0;
        }

        while(i<n){
            price += prices[i];
            i++;
        }
        return price;
    }
};