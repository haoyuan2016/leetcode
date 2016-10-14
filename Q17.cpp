class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits == "")
            return vector<string>{};
        unordered_map<char, string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        vector<string> res;
        string hold;
        helper(res, digits, m, hold, 0);
        return res;
    }
    void helper(vector<string>& res, string digits, unordered_map<char, string> m, string& hold, int cur){
        if(hold.size() == digits.size())
        {
            res.push_back(hold);
            return;
        }
        for(int i = 0; i < m[digits[cur]].size(); i++)
        {
            hold += m[digits[cur]][i];
            helper(res, digits, m, hold, cur + 1);
            hold.pop_back();
        }
    }

};

// This is the dfs method, why it is called dfs, because we go to the deepest first and then trace back.
// note that use different container, i.e., I used map here, can determine the run time.
