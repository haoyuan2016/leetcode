class Solution {
public:
    bool isValid(string s) {
        if(s.empty())
            return true;
        stack<char> m;
        m.push(s[0]);
        for(int i = 1; i < s.length(); i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                m.push(s[i]);
            else
            {
                if(s[i] == ')')
                {
                    if(!m.empty() && m.top() == '(')
                        m.pop();
                    else
                        return false;
                }
                else if(s[i] == '}')
                {
                    if(!m.empty() && m.top() == '{')
                        m.pop();
                    else
                        return false;
                }
                else if(s[i] == ']')
                {
                    if(!m.empty() && m.top() == '[')
                        m.pop();
                    else
                        return false;
                }
                else
                    ;
            }
        }
        return m.empty();
    }
};
// What happen if a stack s is empty but we call s.top()? => it is an error! So check s.empty()? before use s.top();
