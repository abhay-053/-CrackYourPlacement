class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int n = nums.size();
        int j = 0, k = 0;
        for(int i = 2; i< n; i++){
            if(arr1[j] > arr2[k]){
                arr1.push_back(nums[i]);
                j++;
            } else {
                arr2.push_back(nums[i]);
                k++;
            }
        }

        vector<int> ans = arr1;
        ans.insert(ans.end(), begin(arr2), end(arr2));
        return ans;
    }
};