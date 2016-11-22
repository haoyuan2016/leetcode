// Iteration
class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n > 1)
        {
            if(n % 2 != 0) return false;
            else n = n / 2;
        }
        return n == 1;
    }
};
// Recursion
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0)
            return false;
        if(n == 1)
            return true;
        if(n % 2 == 0) return isPowerOfTwo(n / 2);
        return false;
    }
};
// Bit operation
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};
