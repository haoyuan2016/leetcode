class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty()) return;
        stringstream ss(s);
        string tmp;
        stack<string> st;
        while(getline(ss, tmp, ' '))
        {
            if(!tmp.empty())
                st.push(tmp);
        }
        string res = "";
        while(!st.empty())
        {
            res += st.top();
            res += " ";
            st.pop();
        }
        if(!res.empty())
            res.pop_back();
        s = res;
    }
};
