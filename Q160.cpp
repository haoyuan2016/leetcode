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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0;
        int len2 = 0;
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        while(ptr1 != NULL)
        {
            ptr1 = ptr1->next;
            len1++;
        }
        while(ptr2 != NULL)
        {
            ptr2 = ptr2->next;
            len2++;
        }
        ptr1 = headA;
        ptr2 = headB;
        if(len1 > len2)
        {
            int diff = len1 - len2;
            while(diff > 0)
            {
                ptr1 = ptr1->next;
                diff--;
            }
            while(len2 > 0)
            {
                if(ptr1 == ptr2)
                    return ptr1;
                else
                {
                    ptr1 = ptr1->next;
                    ptr2 = ptr2->next;
                }
            }
        }
        else
        {
            int diff = len2 - len1;
            while(diff > 0)
            {
                ptr2 = ptr2->next;
                diff--;
            }
            while(len1 > 0)
            {
                if(ptr1 == ptr2)
                    return ptr1;
                else
                {
                    ptr1 = ptr1->next;
                    ptr2 = ptr2->next;
                }
            }
        }
        return NULL;
    }
};
