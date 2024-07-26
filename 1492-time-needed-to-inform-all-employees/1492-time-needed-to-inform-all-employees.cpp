class Solution {
public:
    int maxTime =0;
    void dfs( unordered_map<int,vector<int>>& mp,vector<int>& informTime, int emp, int time)
    {
        maxTime = max(maxTime, time);
        for(auto i: mp[emp])
        {
            dfs(mp, informTime, i, time+informTime[emp]);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<manager.size();i++)
        {
            int emp = i;
            int managr = manager[i];
            if(managr!= -1)
                mp[managr].push_back(emp);
        }
        dfs(mp, informTime, headID,0);
        return maxTime;
    }
};