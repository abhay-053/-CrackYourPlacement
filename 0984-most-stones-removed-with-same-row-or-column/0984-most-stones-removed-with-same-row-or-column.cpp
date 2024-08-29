class Solution {
public:
    void dfs(int u, vector<vector<int>>& stones, vector<bool>& vis)
    {
        vis[u] = true;
        for(int i=0;i<stones.size();i++)
        {
            if(!vis[i] && (stones[i][0] == stones[u][0] || stones[u][1]== stones[i][1]))
            {
                dfs(i, stones, vis);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n= stones.size();
        int group =0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,stones,vis);
                group++;
            }
        }
        return n-group;
    }
};