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
