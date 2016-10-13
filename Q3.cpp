class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> m;
        int res_length = 0;
        int cur_length = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(m.find(s[i] - 'a') == m.end())
            {
                m[s[i] - 'a'] = i;
                cur_length++;
                res_length = max(res_length, cur_length);
            }
            else  // existing m[s[i] - 'a']
            {
                cur_length = min(i - m.find(s[i] - 'a')->second, ++cur_length);
                res_length = max(res_length, cur_length);
                m[s[i] - 'a'] = i;
            }
        }
        return res_length;
    }
};
// Note: min and max take linear complexity with the length of N, and constant if N == 1 || N == 2
