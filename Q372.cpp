class Solution {
public:
    int base = 1337;
    int powmod(int a, int k)
    {
        a = a % base;
        int result = 1;
        while(k > 0)
        {
            k--;
            result = (result * a) % base;
        }
        return result;
    }
    int superPow(int a, vector<int>& b) {
        if(b.empty()) return 1;
        int tmp = b.back();
        b.pop_back();
        return powmod(superPow(a, b), 10) * (powmod(a, tmp)) % base; 
    }
};
