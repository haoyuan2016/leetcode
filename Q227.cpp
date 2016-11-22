class Solution {
public:
    int calculate(string s) {
        if(s.empty()) return 0;
        int n = s.size();
        int cur = 0;
        int tmp = 0;
        stack<int> st;
        while(cur < n)
        {
            if(s[cur] == ' ')
                ;
            else if(isdigit(s[cur]))
                tmp = 10 * tmp + s[cur] - '0';
            else
            {
                st.push(tmp);
                break;
            }
            cur++;
        }
        if(cur == n)
            st.push(tmp);
        tmp = 0;
        while(cur < n)
        {
            if(s[cur] == ' ')
            {
                cur++;
                continue;
            }
            else if(isdigit(s[cur]))
            {
                tmp = 10 * tmp + s[cur] - '0';
                cur++;
                if(cur == n - 1)
                {
                    st.push(tmp);
                    break;
                }
            }
            else
            {
                int a = cur + 1;
                while(a < n && (isdigit(s[a]) || s[a] == ' '))
                {
                    if (s[a] != ' ')
                        tmp = 10 * tmp + s[a] - '0';
                    a++;
                }
                if(s[cur] == '+')
                    st.push(tmp);
                else if(s[cur] == '-')
                    st.push(-1 * tmp);
                else if(s[cur] == '*')
                {
                    int b = st.top();
                    st.pop();
                    st.push(tmp * b);
                }
                else
                {
                    int b = st.top();
                    st.pop();
                    st.push(b / tmp);
                }
                tmp = 0;
                cur = a;
            }
        }
        int res = 0;
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        return res;
    }
};
