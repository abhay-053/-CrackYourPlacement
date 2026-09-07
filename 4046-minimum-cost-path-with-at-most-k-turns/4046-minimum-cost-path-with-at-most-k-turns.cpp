class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        if(n == 1 && m == 1) {
            return grid[0][0];
        }
        const int INF = 1e9;

        vector<vector<vector<vector<int>>>> dis(n, vector<vector<vector<int>>>(m, vector<vector<int>>(k + 1, vector<int>(4, INF))));
        using T = tuple<int,int,int,int,int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        
        for(int i = 0; i< 4; i++){
            int nr = dr[i];
            int nc = dc[i];
            
            if(nr >= 0 && nr < n && nc >= 0 && nc < m) {
                int cost = grid[0][0] + grid[nr][nc];
                dis[nr][nc][0][i] = cost;
                pq.push({cost, nr, nc, 0, i});
            }
        }

        while(!pq.empty()){
            auto[cost, r, c, kMove, dir] = pq.top();
            pq.pop();


            if(cost != dis[r][c][kMove][dir]){
                continue;
            }
            

            for(int i = 0; i <4 ; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr < 0 || nc < 0 || nr >= n || nc >= m){
                    continue;
                }

                int move = kMove;
                if(dir != i){
                    move += 1;
                }
                
                if(move > k){
                    continue;
                }

                int newCost = cost + grid[nr][nc];


                if(newCost < dis[nr][nc][move][i]){
                    dis[nr][nc][move][i] = newCost;
                    pq.push({newCost, nr, nc, move, i});
                }
            }
        }

        int ans = INF;
        for(int i = 0; i<= k; i++){
            for(int j = 0; j< 4; j++){
                ans = min(ans, dis[n-1][m-1][i][j]);
            }
        }
        return ans == INF ? -1 : ans ;
    }
};