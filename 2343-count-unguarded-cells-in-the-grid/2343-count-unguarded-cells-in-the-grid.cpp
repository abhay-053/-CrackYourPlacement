class Solution { 
public: 
    void solve(int r, int c, vector<vector<int>> &arr) { 
        for (int i = r - 1; i >= 0; i--) { 
            if (arr[i][c] == 3 || arr[i][c] == 2) break; 
            arr[i][c] = 1; 
        } 
        for (int i = r + 1; i < arr.size(); i++) { 
            if (arr[i][c] == 3 || arr[i][c] == 2) break; 
            arr[i][c] = 1; 
        } 
        for (int i = c - 1; i >= 0; i--) { 
            if (arr[r][i] == 3 || arr[r][i] == 2) break; 
            arr[r][i] = 1; 
        } 
        for (int i = c + 1; i < arr[0].size(); i++) { 
            if (arr[r][i] == 3 || arr[r][i] == 2) break; 
            arr[r][i] = 1; 
        } 
    } 
    
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) { 
        vector<vector<int>> arr(m, vector<int>(n, 0)); 
        
        for (auto guard : guards) { 
            arr[guard[0]][guard[1]] = 2; 
        } 
        for (auto wall : walls) { 
            arr[wall[0]][wall[1]] = 3; 
        } 
        
        for (auto guard : guards) { 
            solve(guard[0], guard[1], arr); 
        } 
        
        int ans = 0; 
        for (int i = 0; i < m; i++) { 
            for (int j = 0; j < n; j++) { 
                if (arr[i][j] == 0) { 
                    ans++; 
                } 
            } 
        } 
        
        return ans; 
    } 
};
