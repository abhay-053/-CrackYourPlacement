//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
         vector<vector<int>> mat = grid;
        queue<pair< pair<int,int>, int>> q;
        vector<vector<int>> dist(mat.size(), vector<int>(mat[0].size(),0));
        vector<vector<int>> vis(mat.size(), vector<int>(mat[0].size(),0));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j] == 1){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        int dr[]={0,-1,0,1};
        int dc[]={-1,0,1,0};
        while(!q.empty()){
            auto t= q.front();
            q.pop();
            int r = t.first.first;
            int c = t.first.second;
            int dis = t.second;
            dist[r][c] = dis;
            for(int i=0;i<4;i++){
                int nr= r+ dr[i];
                int nc= c+ dc[i];
                if(nr >=0 && nr<mat.size() && nc>=0 && nc<mat[0].size() && vis[nr][nc] == 0){
                    q.push({{nr,nc},dis+1});
                    vis[nr][nc] = 1;
                }
            }
        }
        return dist;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends