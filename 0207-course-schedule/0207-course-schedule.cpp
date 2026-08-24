class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> indegree(numCourses, 0);
        for(auto &p : prerequisites){
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;
        for(int i = 0; i< numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto nd : graph[node]){
                indegree[nd]--;

                if(indegree[nd] == 0){
                    q.push(nd);
                }
            }
        }

        for(int i = 0; i< numCourses; i++){
            if(indegree[i]){
                return false;
            }
        }
        return true;
    }
};