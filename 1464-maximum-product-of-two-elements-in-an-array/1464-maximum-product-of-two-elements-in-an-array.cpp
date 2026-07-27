class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_1 = 0, max_2 = 0;

        for(int num: nums){
            if(max_1 < num){
                max_2 = max_1;
                max_1 = num;
            } else if(max_2 < num){
                max_2 = num;
            }
        }

        return (max_1 - 1) * (max_2 - 1);
    }
};