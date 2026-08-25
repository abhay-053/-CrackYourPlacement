class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(begin(nums), end(nums));
        int cnt = 1;
        while(st.find(k * cnt) != st.end()){
            cnt++;
        }
        return k * cnt;
    }
};