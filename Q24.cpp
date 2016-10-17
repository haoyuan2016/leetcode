// My solution
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* fake_head = new ListNode(0);
        fake_head->next = head;
        ListNode* ptr = fake_head;
        while(ptr->next != NULL && ptr->next->next != NULL)
        {
            ListNode* n1 = ptr->next;
            ListNode* n2 = ptr->next->next;
            ptr->next = n2;
            n1->next = n2->next;
            n2->next = n1;
            ptr = n1;
        }
        return fake_head->next;
    }
};
