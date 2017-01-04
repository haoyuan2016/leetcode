// solution one:
class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n > 0)
        {
            if(n == 1) return true;
            if(n % 3 != 0) return false;
            n = n / 3;
        }
        return false;
        
    }
};
// solution two:
// note that we cannot use log instead of log10, as error happen when n = 243 like a conincidence.
class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n > 0)
        {
            if(n == 1) return true;
            if(n % 3 != 0) return false;
            n = n / 3;
        }
        return false;
        
    }
};
// solution three:
class Solution {
public:
    bool isPowerOfThree(int n) {
        int a = pow(3,19);
        if(n > 0 && a % n == 0) return true;
        return false;
    }
};
