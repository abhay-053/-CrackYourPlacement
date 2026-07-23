class Solution {
public:
    #define T tuple<int,int,int>
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(); 
        int m = heights[0].size();


        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        priority_queue<T, vector<T>, greater<T>> pq;
        dist[0][0] = 0;
        pq.push({0, 0, 0});
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        while(!pq.empty()){
            auto [dis, r, c] = pq.top();
            pq.pop();

            for(int i = 0 ; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nc >= 0 && nr < n && nc < m){
                    if(dist[nr][nc] > max(dis , abs(heights[nr][nc]- heights[r][c]))){
                        dist[nr][nc] = max(dis , abs(heights[nr][nc]- heights[r][c]));
                        pq.push({dist[nr][nc], nr, nc});
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};