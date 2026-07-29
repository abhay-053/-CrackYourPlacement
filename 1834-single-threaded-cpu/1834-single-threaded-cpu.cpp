class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<vector<int>> task(n, vector<int>(3));

        for(int i = 0; i < n; i++){
            task[i][0] = tasks[i][0];
            task[i][1] = tasks[i][1];
            task[i][2] = i;
        }

        sort(begin(task), end(task));
        long long currTime = 0;
        priority_queue<tuple<int, int>,vector<tuple<int, int>>,greater<tuple<int, int>>> pq;
        int i = 0;

        vector<int> res ;
        while(i < n || !pq.empty()){
            
            while(i< n && task[i][0] <= currTime){
                pq.push({task[i][1], task[i][2]});
                i++;
            }

            if(pq.empty()){
                currTime = task[i][0];
            } else {
                auto [time, idx] = pq.top();
                pq.pop();
                res.push_back(idx);
                currTime += time;
            }
        }
        return res;
        
    }
};