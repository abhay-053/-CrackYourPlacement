class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] != 0){
            return -1;
        }

        queue<tuple<int,int,int>> q;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        q.push({0,0,1});

        int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        while(!q.empty()){
            auto [r, c, step] = q.front();
            q.pop();

            if(r == n-1 && c== n-1){
                return step;
            }

            if( c == 0){
                if(r + 1 < n){
                    if(!vis[r+1][c] && grid[r+1][c] == 0){
                        q.push({r+1, c, step + 1});
                        vis[r+1][c] = 1;
                    } 

                    if(!vis[r+1][c+1] && grid[r+1][c+1] == 0){
                        q.push({r+1, c+1, step+1});
                        vis[r+1][c+1] = 1;
                    }
                }
            }

            if( c == n-1){
                if(r + 1 < n){
                    if(!vis[r+1][c] && grid[r+1][c] == 0){
                        q.push({r+1, c, step + 1});
                        vis[r+1][c] = 1;
                    } 

                    if(!vis[r+1][c-1] && grid[r+1][c-1] == 0){
                        q.push({r+1, c-1, step + 1});
                        vis[r+1][c-1] = 1;
                    }
                }
            }

            if(r == 0){
                if(c+1 < n){
                    if(r+1 < n && !vis[r+1][c+1] && grid[r+1][c+1] == 0){
                        q.push({r+1, c+1, step + 1});
                        vis[r+1][c+1] = 1;
                    }
                    if(!vis[r][c+1] && grid[r][c+1] == 0){
                        q.push({r, c+1, step+1});
                        vis[r][c+1] = 1;
                    }
                }
            }

            if(r > 0 && c > 0 && c != n-1){
                for(int i = 0; i<8; i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if(nr < n && nc < n && !vis[nr][nc] && grid[nr][nc] == 0){
                        q.push({nr, nc, step+1});
                        vis[nr][nc] = 1;
                    }
                }
            }
        }
        return -1;
    }
};