class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        if(q1.empty() && q2.empty())
            q1.push(x);
        else if(!q1.empty() && q2.empty())
        {
            q2.push(x);
            while(!q1.empty())
            {
                int tmp = q1.front();
                q1.pop();
                q2.push(tmp);
            }
        }
        else // q1.empty() && !q2.empty()
        {
            q1.push(x);
            while(!q2.empty())
            {
                int tmp = q2.front();
                q2.pop();
                q1.push(tmp);
            }
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        if(!q1.empty())
            q1.pop();
        else
            q2.pop();
    }

    // Get the top element.
    int top() {
        if(!q1.empty())
            return q1.front();
        else
            return q2.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty() && q2.empty();
        
    }
private:
    queue<int> q1, q2;
};
