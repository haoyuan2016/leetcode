// Note that this question is case sensitive.
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
// Another solution from leetcode discuss
class Solution {
public:
    string reverseVowels(string s) {
        if(s.empty()) return s;
        int start = 0;
        int end = s.size() - 1;
        string vowels = "aeiouAEIOU";
        while(start < end)
        {
            while(start < end && vowels.find(s[start]) == string::npos)
                start++;
            while(start < end && vowels.find(s[end]) == string::npos)
                end--;
            char tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
            start++;
            end--;
        }
        return s;
    }
};
