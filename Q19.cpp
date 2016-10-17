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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // solution with 1 round
        ListNode* fake_head = new ListNode(0);
        fake_head->next = head;
        ListNode* ptr1 = fake_head;
        ListNode* ptr2 = fake_head;
        int tmp = n;
        while(tmp > 0)
        {
            ptr1 = ptr1->next;
            tmp--;
        }
        while(ptr1->next != NULL)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        ptr2->next = ptr2->next->next;
        return fake_head->next;
           
        /* solution with 2 rounds
        int len = 0;
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* ptr = head;
        while(ptr != NULL)
        {
            ptr = ptr->next;
            len++;
        }
        ListNode* ptr1 = new_head;
        int tmp = len - n;
        while(tmp > 0)
        {
            ptr1 = ptr1->next;
            tmp--;
        }
        ptr1->next = ptr1->next->next;
        return new_head->next;
        */
    }
};
