//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        int n=0;
        vector<int> arr(26,0);
        for(auto i: str)
        {
            if(i!= ' ')
            {
                arr[i-'a']++;
                n++;
            }
        }
        if(n<26)return false;
        //cout<<n<<endl;
        int count =0;
        for(auto i: arr)
        {
            if(i==0)count++;
        }
        
        if(count<= k)return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends