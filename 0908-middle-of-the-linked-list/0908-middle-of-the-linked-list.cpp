class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* ptr=head;
        int count=0;
        while(ptr!=NULL)
        {
            count++;
            ptr=ptr->next;
        }
        ptr=head;
        for(int i=0;i<count/2;i++)
        ptr=ptr->next;
        return ptr;
    }
};