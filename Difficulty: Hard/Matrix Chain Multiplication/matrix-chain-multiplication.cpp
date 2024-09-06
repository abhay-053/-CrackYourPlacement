//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public: 
    int dp[101][101];
    int find(int i, int j, int arr[])
    {
        if(i==j)return 0;
        
        if(dp[i][j] != -1)return dp[i][j];
        int mini = INT_MAX;
        
        for(int k = i;k<j;k++)
        {
            int steps = arr[i-1] * arr[k] * arr[j] + find(i,k,arr) + find(k+1,j,arr);
            
            if(steps < mini)
            {
                mini = steps;
            }
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp,-1,sizeof(dp));
       return find(1,N-1,arr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends