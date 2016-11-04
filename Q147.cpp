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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        ListNode* fakeHead = new ListNode(INT_MIN);
        fakeHead->next = head;
        ListNode* pre = fakeHead;
        ListNode* cur = pre->next;
        ListNode* tail = cur->next;
        while(cur != NULL)
        {
            if(cur->val >= pre->val)
            {
                if(tail != NULL) 
                    tail = tail->next;
                cur = cur->next;
                pre = pre->next;
            }
            else
            {
                ListNode* tmp = fakeHead;
                while(tmp->next != cur)
                {
                    if(tmp->next->val > cur->val)
                    {
                        pre->next = tail;
                        cur->next= tmp->next;
                        tmp->next = cur;
                        break;
                    }
                    else
                        tmp = tmp->next;
                }
                //pre = cur->next;
                cur = tail;
                if(cur != NULL) tail = cur->next;
            }
        }
        return fakeHead->next;
    }
};
