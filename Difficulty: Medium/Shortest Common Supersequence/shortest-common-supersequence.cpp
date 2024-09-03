//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    int dp[101][101];
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string str1, string str2, int m, int n)
    {
        memset(dp,-1,sizeof(dp));
        return solve(str1,str2,0,0);
    }
    
    int solve(string str1, string str2, int i, int j)
    {
        
        if(i==str1.size())return str2.size()-j;
        if(j==str2.size())return str1.size()-i;
        
        if(dp[i][j] != -1)return dp[i][j];
        if(str1[i] == str2[j])
        return dp[i][j]= 1+solve(str1,str2,i+1,j+1);

        else return dp[i][j] = 1 + min(solve(str1, str2, i+1, j), solve(str1, str2, i, j+1));
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends