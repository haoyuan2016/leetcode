// My first round code, it only beats 10%
// I use the level traversal method and the idea of DP stored in a queue.
// A set is applied to delect the duplicates.
// note that we cannot iterator a queue use for(auto i : queue), if we want to itertor a queue, we have to use iterator or use deque.
// But if we use deque, access element is not "push" but "insert".
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        queue<string> q;
        q.push("()");
        int cur = 1;
        while(cur < n)
        {
            cur++;
            int z = q.size();
            set<string> s;
            while(z > 0)
            {
                z--;
                string tmp = q.front();
                q.pop();
                int tmpLength = tmp.length();
                for(int j = 0; j <= tmpLength / 2; j++)
                {
                    string tmp_string = tmp.substr(0,j) + "()" + tmp.substr(j);
                    s.insert(tmp_string);
                }
            }
            for(string k : s)
                q.push(k);
        }
        vector<string> res;
        while(!q.empty())
        {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
