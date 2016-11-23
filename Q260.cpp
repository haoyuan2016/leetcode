// This problem is interesting, we need to find the xor of a ^ b, and then divide the whole nums into two subset by the first bit difference.
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int tmp = 0;
        for(int a : nums)
            tmp = tmp ^ a;
        int index = 0;
        while((tmp & 1) != 1)
        {
            tmp = tmp >> 1;
            index++;
        }
        vector<int> t1, t2;
        for(int b : nums)
        {
            int tmp = b;
            tmp = tmp >> index;
            if(tmp & 1 == 1)
                t1.push_back(b);
            else
                t2.push_back(b);
        }
        int c;
        for(auto a : t1)
            c = c ^ a;
        int d;
        for(auto b : t2)
            d = d ^ b;
        vector<int> res{c, d};
        return res;
    }
};
