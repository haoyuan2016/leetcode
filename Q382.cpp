// Solution one: by calculating the length of the single list;
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        ListNode* ptr = head;
        fake_head = head;
        while(ptr)
        {
            ptr = ptr->next;
            length++;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int a = rand() % length;
        ListNode* tmp = fake_head;
        while(a)
        {
            a--;
            tmp = tmp->next;
        }
        return tmp->val;
    }
private:
    int length = 0;
    ListNode* fake_head = NULL;
};
