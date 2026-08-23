class Solution {
public:
    vector<vector<int>> mergeInterval(vector<vector<int>>& intervals){
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        pair<int,int> pr = {intervals[0][0], intervals[0][1]};

        int n = intervals.size();
        for(int i = 1; i< n; i++){
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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        vector<vector<int>> ans = mergeInterval(intervals);
        return ans;
    }
};