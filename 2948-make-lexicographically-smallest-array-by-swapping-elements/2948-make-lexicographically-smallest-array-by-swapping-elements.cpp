class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> arr = nums;
        sort(begin(arr), end(arr));
        int group = 0;
        int n = nums.size();
        unordered_map<int,int> numToGroup;
        numToGroup[arr[0]] = group;

        unordered_map<int, deque<int>> groupList;
        groupList[group].push_back(arr[0]);

        for(int i = 1; i< n; i++){
            if(abs(arr[i] - arr[i-1]) > limit){
                group++;
            } 
            numToGroup[arr[i]] = group;
            groupList[group].push_back(arr[i]);
        }

        vector<int> ans(n);
        for(int i = 0; i< n; i++){
            int num = nums[i];
            int group = numToGroup[num];

            ans[i] = groupList[group].front();
            groupList[group].pop_front();
        }
        return ans;
    }
};