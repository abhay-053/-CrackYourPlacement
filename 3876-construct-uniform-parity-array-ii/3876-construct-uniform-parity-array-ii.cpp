class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minEven = INT_MAX;
        int minOdd = INT_MAX;
        int n = nums1.size();
        for(int i = 0; i< n; i++){
            if(nums1[i] % 2 == 0){
                minEven = min(minEven, nums1[i]);
            } else {
                minOdd = min(minOdd, nums1[i]);
            }
        }
        if(minOdd == INT_MAX){
            return true;
        }
        if(minEven == INT_MAX){
            return true;
        }
        return minEven > minOdd;
    }
};