class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void dfs(int node, vector<vector<int>> &graph, vector<int> path){
        path.push_back(node);

        if(node == n - 1){
            ans.push_back(path);
        }
        for(auto nd: graph[node]){
            dfs(nd, graph, path);
        }

        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vector<int> path;

        dfs(0, graph, path);
        return ans;
    }
};