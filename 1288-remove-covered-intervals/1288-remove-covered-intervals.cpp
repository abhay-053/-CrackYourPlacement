class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int last = 0;
        int first = -1;
        int count = 0;
        for(int i = 0; i< n; i++){

            if(last >= intervals[i][1]){
                continue;
            } else {
                if(first < intervals[i][0]){
                    count++;
                }
                last = intervals[i][1];
                first = intervals[i][0];
            }
        }
        return count;
    }
};