class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        st2.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(!st1.empty())
        {
            st1.pop();
            return;
        }
        else
        {
            while(!st2.empty())
            {
                int tmp = st2.top();
                st2.pop();
                st1.push(tmp);
            }
        }
        st1.pop();
    }

    // Get the front element.
    int peek(void) {
        if(!st1.empty())
            return st1.top();
        else
        {
            while(!st2.empty())
            {
                int tmp = st2.top();
                st2.pop(), st1.push(tmp);
            }
        }
        return st1.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return st1.empty() && st2.empty();
    }
private:
    stack<int> st1;
    stack<int> st2;
};
