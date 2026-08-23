class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        
        vector<vector<int>> ans;
        int n = intervals.size();
        pair<int,int> pr = {intervals[0][0], intervals[0][1]};
        for(int i = 1; i < n; i++){
            if(pr.second < intervals[i][0]){
                ans.push_back({pr.first, pr.second});
                pr = {intervals[i][0], intervals[i][1]};
            } else {
                pr.second = max(pr.second, intervals[i][1]);
            }
        }

        ans.push_back({pr.first, pr.second});
        return ans;
    }
};