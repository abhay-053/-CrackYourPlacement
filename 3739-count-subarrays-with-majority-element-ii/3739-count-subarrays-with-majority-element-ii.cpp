#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> prefix(n+1, 0);
        int j = 1;
        for(auto &i: nums){
            if(i == target){
                prefix[j] = 1;
            } else {
                prefix[j] = -1;
            }
            j++;
        }

        for(int i = 1; i<= n; i++){
            prefix[i] += prefix[i-1];
        }

        tree<pair<int,int>, null_type, less<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> st;
        long long ans = 0;
        for(int i = 0; i<= n; i++){
            ans += st.order_of_key({prefix[i], -1});
            st.insert({prefix[i], i });
        }

        return ans;
    }
};
