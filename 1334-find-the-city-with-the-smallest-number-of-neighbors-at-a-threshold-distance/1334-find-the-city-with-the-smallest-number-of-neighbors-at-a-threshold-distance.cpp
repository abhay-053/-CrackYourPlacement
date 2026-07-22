class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));

        for(int i = 0; i< n; i++){
            dis[i][i] = 0;
        }
        for(auto &i: edges){
            int u = i[0];
            int v = i[1];
            int w = i[2];

            dis[u][v] = w;
            dis[v][u] = w;
        }

        for(int k = 0; k < n; k++){
            for(int i = 0; i< n; i++){
                for(int j = 0; j< n; j++){
                    if(dis[i][k] != INT_MAX && dis[k][j] != INT_MAX){
                        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                    }
                }
            }
        }

        // for(auto i: dis){
        //     for(auto j: i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }

        vector<int> dist(n, 0);
        for(int i = 0; i< n; i++){
            int cnt = 0;
            for(int j = 0; j< n; j++){
                if(i!= j && dis[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            dist[i] = cnt;
        }

        int mini = *min_element(begin(dist), end(dist));
        int city ;
        for(int i = 0; i< n; i++){
            if(dist[i] == mini){
                city = i;
            }
        }
        return city;
    }
};