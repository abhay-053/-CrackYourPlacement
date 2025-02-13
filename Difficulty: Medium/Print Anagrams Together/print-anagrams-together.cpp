//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        vector<vector<string>> ans;
        unordered_set<string> s;
        for(int i=0;i<arr.size();i++){
            vector<string> ar;
            if(s.find(arr[i]) != s.end())continue;
            ar.push_back(arr[i]);
            s.insert(arr[i]);
            
            for(int j=i+1;j<arr.size();j++){
                unordered_map<char,int> st;
                for(auto k: arr[i])st[k] ++;;
                int flag = 1;
                for(auto l:arr[j]){
                    if(st.find(l) == st.end()){
                        flag =0;
                        break;
                    }
                    else{
                        st[l]--;
                        if(st[l] == 0){
                            st.erase(l);
                        }
                    }
                }
                if(flag && arr[i].size() == arr[j].size()){
                    s.insert(arr[j]);
                    ar.push_back(arr[j]);
                }
            }
            ans.push_back(ar);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends