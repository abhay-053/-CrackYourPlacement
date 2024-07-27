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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ptr1 = list1, *ptr2= list2;
        if(ptr1==NULL)return list2;
        if(ptr2==NULL)return list1;
        ListNode *head = NULL,*cur=NULL;
        while(ptr1!=NULL && ptr2!=NULL)
        {
            ListNode* tmp ;
            if(ptr1->val < ptr2->val)
            {
                tmp = new ListNode(ptr1->val);
                ptr1=ptr1->next;
            }
            else 
            {
                tmp = new ListNode(ptr2->val);
                ptr2=ptr2->next;
            }
            if(head == NULL)
            {
                head=cur=tmp;
            }
            else 
            {
                cur->next=tmp;
                cur=cur->next;
            }
        }
        while(ptr1!=NULL)
        {
            ListNode* tmp = new ListNode(ptr1->val);
            cur->next=tmp;
            cur=cur->next;
            ptr1=ptr1->next;
        }
        while(ptr2!=NULL)
        {
            ListNode* tmp = new ListNode(ptr2->val);
            cur->next=tmp;
            cur=cur->next;
            ptr2=ptr2->next;
        }
        return head;
    }
};