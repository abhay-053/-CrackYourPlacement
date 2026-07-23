class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target){
            return 0;
        }
        unordered_map<int, vector<int>> graph;

        int n = routes.size();
        for(int i = 0; i< n; i++){
            int m = routes[i].size();
            for(int j = 0; j < m; j++){
               graph[routes[i][j]].push_back(i);
            }
        }

        vector<int> vis(501, 0);

        queue<int> q;

        for(auto i: graph[source]){
            q.push(i);
            vis[i] = 1;
        }
        int busCount = 1;
        while(!q.empty()){

            int size = q.size();
            while(size --){
                int route = q.front();
                q.pop();

                for(int stops : routes[route]){
                    if(stops == target){
                        return busCount;
                    }

                    for(int nxtRoute: graph[stops]){
                        if(!vis[nxtRoute]){
                            q.push(nxtRoute);
                            vis[nxtRoute] = 1;
                        }
                    }
                }
            }
            busCount ++;
        }
        return -1;
    }
};