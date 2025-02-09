//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        // code here
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        vector<vector<int>> dist(rows, vector<int>(columns, 1e7));
        dist[0][0] = 0;
        while(!q.empty())
        {
            int r = q.front().second.first;
            int c = q.front().second.second;
            int diff = q.front().first;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<rows && nc>=0 && nc<columns)
                {
                    int newEffort = max(abs(heights[nr][nc] - heights[r][c]), diff);
                    if(dist[nr][nc] > newEffort)
                    {
                        dist[nr][nc] = newEffort;
                        q.push({newEffort, {nr,nc}});
                    }
                }
            }
        }
        return dist[rows-1][columns-1];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends