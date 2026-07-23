class Solution {
public:
    #define T tuple<int,int,int>
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();


        priority_queue<T, vector<T> , greater<T>>pq;
        pq.push({grid[0][0], 0, 0});

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        while(!pq.empty()){
            auto [dis, r, c] = pq.top();
            pq.pop();

            if(dist[r][c] < dis ){
                continue;
            }
            
            for(int i = 0; i< 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nc >= 0 && nr < n && nc < n ){
                    if(dist[nr][nc] > max(dis, grid[nr][nc])){
                        dist[nr][nc] = max(dis, grid[nr][nc]);
                        pq.push({dist[nr][nc], nr, nc});
                    }
                }
                
            }
        }
        return dist[n-1][n-1];
    }
};