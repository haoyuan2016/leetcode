// Another solution is to like find the circle in linked list. We use a slow and a fast, and check whether slow and fast meets.
// See https://discuss.leetcode.com/topic/12587/my-solution-in-c-o-1-space-and-no-magic-math-property-involved
class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        while(true)
        {
            int cur = 0;
            while(n > 0)
            {
                int tmp = n % 10;
                n = n / 10;
                cur += tmp * tmp;
            }
            if(cur == 1) return true;
            else 
            {
                if(s.find(cur) == s.end())
                {
                    s.insert(cur);
                    n = cur;
                }
                else
                    return false;
            }
        }
        return false;
    }
};
