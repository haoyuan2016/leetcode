class Solution {
public:
    string reverseVowels(string s) {
        stack<char> st;
        for(auto & i : s)
        {
            if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u' || i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U')
            {
                st.push(i);
                i = 'o';
            }
        }
        for(auto & i : s)
        {
            if(i == 'o')
            {
                i = st.top();
                st.pop();
            }
        }
        return s;
    }
};
