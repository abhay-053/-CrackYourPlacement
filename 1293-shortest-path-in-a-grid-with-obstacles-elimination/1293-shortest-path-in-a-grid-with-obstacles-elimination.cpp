class Solution {
public:
    #define T tuple<int,int,int>
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(k+1, 0)));

        queue<T> q;
        q.push({0, 0, k});

        vis[0][0][k] = 1;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        int step = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto [r, c, remK] = q.front();
                q.pop();

                if(r == n-1 && c == m-1){
                    return step;
                }
                for(int i = 0; i<4; i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    int tmp = remK;

                    if(nr >= 0 && nc >= 0 && nr < n && nc < m ) {
                        if(grid[nr][nc] == 1 ){
                            if(remK >= 1){
                                tmp = tmp - 1;
                            } else {
                                continue;
                            }
                        }

                        if(!vis[nr][nc][tmp]){
                            q.push({nr, nc, tmp});
                            vis[nr][nc][tmp] = 1;
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};