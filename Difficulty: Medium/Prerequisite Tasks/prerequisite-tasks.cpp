//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, int P, vector<pair<int, int>>& prerequisites) {
    unordered_map<int, vector<int>> mp;
    vector<int> indegree(N, 0);

    // Build the adjacency list and indegree array
    for (auto i : prerequisites) {
        int a = i.first;
        int b = i.second;
        mp[b].push_back(a);
        indegree[a]++;
    }
    
    int task = 0;
    // Initialize the queue with all nodes that have an indegree of 0
    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            task++;
        }
    }


    // Process the nodes
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();

        for (auto i : mp[tmp]) {
            indegree[i]--;
            if (indegree[i] == 0) {
                q.push(i);
                task++;
            }
        }
    }

    return task == N;
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends