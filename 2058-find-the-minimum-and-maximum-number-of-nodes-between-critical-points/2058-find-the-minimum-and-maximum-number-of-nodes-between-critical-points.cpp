/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> criticalPoints;

        int prev = head->val;
        ListNode* ptr = head -> next;
        int cnt = 2;
        while(ptr != NULL){
            int next;
            if(ptr -> next != NULL){
                next = ptr->next->val;
            }

            if(prev < ptr->val && ptr ->val > next){
                criticalPoints.push_back(cnt);
            } 
            if(prev > ptr->val && ptr ->val < next){
                criticalPoints.push_back(cnt);
            }

            prev = ptr -> val;
            ptr = ptr -> next;
            cnt++;
        }

        for(auto i: criticalPoints){
            cout<<i<<" ";
        }
        if(criticalPoints.size() <= 1){
            return {-1, -1};
        }

        int mini = INT_MAX;
        for(int i = 1; i< criticalPoints.size(); i++){
            mini = min(mini, criticalPoints[i] - criticalPoints[i-1]);
        }
        int maxi = criticalPoints.back() - criticalPoints[0];

        return {mini, maxi};
        
    }
};