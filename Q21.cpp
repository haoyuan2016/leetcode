/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* fake_head = new ListNode(0);
        ListNode* ptr = fake_head;
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val < l2->val)
            {
                ptr->next = l1;
                ptr = ptr->next;
                l1 = l1->next;
            }
            else
            {
                ptr->next = l2;
                ptr = ptr->next;
                l2 = l2->next;
            }
        }
        if(l1 != NULL)
        {
            ptr->next = l1;
            l1 = l1->next;
            ptr = ptr->next;
        }
        if(l2 != NULL)
        {
            ptr->next = l2;
            l2 = l2->next;
            ptr = ptr->next;
        }
        return fake_head->next;
    }
};
