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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = NULL;
        while(fast != NULL && fast->next != NULL)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        head = sortList(head);
        slow = sortList(slow);
        head = merge(slow, head);
        return head;
    }
    ListNode* merge(ListNode* ptr1, ListNode* ptr2)
    {
        ListNode* newHead = new ListNode(0);
        ListNode* ptr = newHead;
        while(ptr1 != NULL && ptr2 != NULL)
        {
            if(ptr1->val < ptr2->val)
            {
                ptr->next = ptr1;
                ptr = ptr->next;
                ptr1 = ptr1->next;
            }
            else // 
            {
                ptr->next = ptr2;
                ptr = ptr->next;
                ptr2 = ptr2->next;
            }
        }
        if(ptr1 != NULL)
        {
            ptr->next = ptr1;
        }
        if(ptr2 != NULL)
        {
            ptr->next = ptr2;
        }
        return newHead->next;
    }
};
