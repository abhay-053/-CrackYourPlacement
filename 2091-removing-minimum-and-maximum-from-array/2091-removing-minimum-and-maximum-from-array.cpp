class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxVal = *max_element(begin(nums), end(nums));
        int minVal = *min_element(begin(nums), end(nums));

        int id1 = -1, id2 = -1;
        int n = nums.size();
        for(int i = 0; i< n; i++){
            if(nums[i] == maxVal){
                id1 = i;

                if(id2 != -1){
                    break;
                }
            }

            if(nums[i] == minVal){
                id2 = i;

                if(id1 != -1){
                    break;
                }
            }
        }

        int ans = max(id1, id2) + 1;
        ans = min(ans, max(n-id1, n - id2));
        if(id1 > id2){
            id1 = n - id1;
            ans = min(ans, id1 + id2 + 1 );
        } else {
            id2 = n- id2;
            ans = min(ans, id2 + id1 + 1);
        }
        return ans;
    }
};