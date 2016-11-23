class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res{1};
        int index2 = 0, index3 = 0, index5 = 0;
        while(n > 1)
        {
            n--;
            // compare tmp1 * index1, tmp2 * index2, tmp3 index3
            int curMin = min(2 * res[index2], min(3 * res[index3], 5 * res[index5]));
            res.push_back(curMin);
            if(curMin == 2 * res[index2])
                index2++;
            if(curMin == 3 * res[index3])
                index3++;
            if(curMin == 5 * res[index5])
                index5++;
        }
        return res.back();
    }
};
