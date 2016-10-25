class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res{0};
        if(n == 0) return res;
        int cur = 1;
        while(cur <= n)
        {
            int lens = res.size();
            for(int i = lens - 1; i >= 0; i--)
                res.push_back(res[i] + pow(2, cur - 1));
            cur++;
        }
        return res;
    }
};
