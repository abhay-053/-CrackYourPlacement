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
    ListNode* reverse(ListNode* head){
        ListNode *curr = head, *prev = NULL, *nxt = NULL;

        while(curr){
            nxt = curr -> next; 
            curr -> next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* slow = head; 
        ListNode* fast = head;

        while(fast){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* revList = reverse(slow);
        fast = head;
        int sum = 0;
        while(revList != NULL){
            sum = max(sum, revList -> val + fast -> val);
            revList = revList -> next; 
            fast = fast -> next;
        }
        return sum;
    }
};