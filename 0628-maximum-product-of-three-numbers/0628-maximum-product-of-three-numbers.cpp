class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max_1 = -1001, max_2 = -1001, max_3 = -1001;
        int max_11 = 1001, max_22 = 1001;
        for(int num: nums){
            if(num > max_1){
                max_3 = max_2;
                max_2 = max_1;
                max_1 = num;
            } else if( num > max_2){
                max_3 = max_2;
                max_2 = num;
            } else if(num > max_3){
                max_3 = num;
            }

            if( num < max_11){
                max_22 = max_11;
                max_11 = num;
            } else if( num < max_22){
                max_22 = num;
            }
        }
        // cout<<max_1<<" "<<max_2<<" "<<max_11<<" "<<max_22<<" "<<max_3<<endl;
        
        int ans = max_1 * max_2 * max_3 ;

        ans = max(max_11 * max_22 * max_1 , ans);
        return ans;
    }
};