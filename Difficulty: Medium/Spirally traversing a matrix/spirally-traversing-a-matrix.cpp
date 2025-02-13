//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        int n= mat.size(), m= mat[0].size();
        int maxr = n-1, maxc= m-1, minr=0, minc=0;
        vector<int> ans;
        int count = 0;
        int total = n*m;
        while(count<total){
            for(int i= minc; i<= maxc&& count<total;i++){
                ans.push_back(mat[minr][i]);
                count++;
            }
            minr++;
            
            for(int i=minr;i<=maxr && count<total;i++){
                ans.push_back(mat[i][maxc]);
                count++;
            }
            maxc--;
            
            for(int i= maxc; i>=minc&& count<total;i--){
                ans.push_back(mat[maxr][i]);
                count++;
            }
            maxr--;
            
            for(int i= maxr;i>=minr&& count<total;i--){
                ans.push_back(mat[i][minc]);
                count++;
            }
            minc++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends