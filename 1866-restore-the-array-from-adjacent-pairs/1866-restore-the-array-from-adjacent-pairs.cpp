class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& edge, int source, vector<int>& st,int prev) 
    {
        st.push_back(source);
        for (auto i : edge[source]) {
            if(i!=prev)
            dfs(edge, i, st,source);
        }
    }

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        
        unordered_map<int, vector<int>> edge;

        // Populate the edge vector and calculate the degree of each node
        for (auto& pair : adjacentPairs) {
            int a = pair[0];
            int b = pair[1];
            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        vector<int> ans;
        
        // Find a node with degree 1 to start DFS
        for (auto i: edge) 
        {
            if (i.second.size() == 1) 
            {
                dfs(edge, i.first, ans,INT_MAX);
                break;
            }
        }

        return ans;
    }
};
