class Solution {
public:
    int addDigits(int num) {
        if(num < 10) return num;
        int tmp = 0;
        while(num > 0)
        {
            int rem = num % 10;
            num = num / 10;
            tmp += rem;
        }
        if(tmp < 10)
            return tmp;
        else
            return addDigits(tmp);
    }
};
