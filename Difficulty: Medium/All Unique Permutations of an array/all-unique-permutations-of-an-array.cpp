//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void helper(set<vector<int>>& st, vector<int> &arr, vector<int> &ans,vector<int> &vis)
    {
        if(arr.size()== ans.size())
        {
            st.insert(ans);
            return ;
        }
        for(int i=0;i<arr.size();i++)
        {
            if(!vis[i])
            {
                vis[i] = 1;
                ans.push_back(arr[i]);
                helper(st,arr,ans,vis);
                ans.pop_back();
                vis[i] = 0;
            }
        }

    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        sort(arr.begin(),arr.end());
        
        set<vector<int>> st;
        vector<int> ans;
        vector<int> vis(n,0);
        helper(st,arr,ans, vis);
        
        vector<vector<int>> res(st.begin(),st.end());
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends