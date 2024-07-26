class Solution {
public:
    bool dfs(int idx , vector<int>& vis, vector<int>& inrecur, vector<vector<int>>& graph)
    {
        vis[idx] = 1;
        inrecur[idx] = 1;

        for(auto i: graph[idx])
        {
            if(!vis[i] && dfs(i, vis,inrecur, graph))
            {
                return true;
            }

            else if(inrecur[i] == 1){
                return true;
            }
        }

        inrecur[idx]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> inrecur(n,0);
        for(int i=0;i<n;i++)
        {
                if(!vis[i])
                {
                    dfs(i, vis, inrecur, graph);
                }
        }
        for(auto i=0;i<n;i++)
        {
            if(inrecur[i]==0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};