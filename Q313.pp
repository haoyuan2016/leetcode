class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n == 1) return 1;
        vector<int> res;
        res.push_back(1);
        map<int,int> m;
        for(auto i : primes)
            m[i] = 0;
        while(res.size() < n)
        {
            int tmp = INT_MAX;
            for(auto i : m)
            {
                if (tmp > i.first * res[i.second])
                    tmp = i.first * res[i.second];
            }
            for(auto i : m)
            {
                if (tmp == i.first * res[i.second])
                    m[i.first]++;
            }
            res.push_back(tmp);
        }
        return res.back();
    }
};
