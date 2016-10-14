class Solution {
public:
    string intToRoman(int num) {
        string res;
        if(num >= 1000)
        {
            int tmp = num / 1000;
            while(tmp > 0)
            {
                res += "M";
                tmp--;
            }
            num = num % 1000;
        }
        if(num >= 900)
            res += "CM";
        else if(num >= 500)
        {
            int tmp = num;
            res += "D";
            tmp = tmp - 500;
            while(tmp >= 100)
            {
                res += "C";
                tmp = tmp - 100;
            }
        }
        else if(num >= 400)
            res += "CD";
        else // num < 400
        {
            int tmp = num;
            while(tmp >= 100)
            {
                res += "C";
                tmp = tmp - 100;
            }
        }
        num = num % 100;
        if(num >= 90)
            res += "XC";
        else if(num >= 50)
        {
            int tmp = num - 50;
            res += "L";
            while(tmp >= 10)
            {
                res += "X";
                tmp -= 10;
            }
        }
        else if(num >= 40)
            res += "XL";
        else // num < 40
        {
            int tmp = num;
            while(tmp >= 10)
            {
                res += "X";
                tmp = tmp - 10;
            }
        }
        num = num % 10;
        if(num >= 9)
            res += "IX";
        else if(num >= 5)
        {
            int tmp = num - 5;
            res += "V";
            while(tmp >= 1)
            {
                res += "I";
                tmp--;
            }
        }
        else if(num >= 4)
            res += "IV";
        else
        {
            int tmp = num;
            while(tmp >= 1)
            {
                res += "I";
                tmp--;
            }
        }
        return res;
    }
};
// note: write it case by case from the most significant digit to the least.
// 4 and 9 are two special cases
