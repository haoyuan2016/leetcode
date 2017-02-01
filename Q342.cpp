// solution one:
class Solution {
public:
    bool isPowerOfFour(int num) {
        while(num > 1 && num % 4 == 0)
            num = num / 4;
        if(num == 1) return true;
        return false;
    }
};
// solution two:
class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num > 0) && ((num & (num - 1)) == 0) && ((num & 0x55555555) != 0);
    }
};
