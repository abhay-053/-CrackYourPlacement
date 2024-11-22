//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        int dp[100001][2][2];
        int solve(vector<int>&price, int idx, int buy,int total)
        {
            if(idx>=price.size() || total >= 2)
            {
                return 0;
            }
            if(dp[idx][buy][total]!= -1)return dp[idx][buy][total];
            int take=0, not_take=0;
            if(buy)
            {
                take = -price[idx] + solve(price, idx+1, 0, total);
                not_take = solve(price, idx+1, 1, total);
            }
            else
            {
                take = price[idx] + solve(price, idx+1, 1, total + 1);
                not_take = solve(price, idx+1, 0, total);
            }
            
            
            return dp[idx][buy][total]=max(take, not_take);
        }
        int maxProfit(vector<int>&price){
            //Write your code here..
            memset(dp, -1, sizeof(dp));
            return solve(price,0, 1,0);
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    
cout << "~" << "\n";
}

}

// } Driver Code Ends