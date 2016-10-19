// Actually we can directly save the result in a string with maximum length num1.length() + num2.length()
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        string res = "";
        for(int i = num2.size() - 1; i >= 0; i--)
        {
            int carry = 0;
            string tmp = "";
            for(int j = num1.size() - 1; j >= 0; j--)
            {
                int n = (carry + (num1[j] - '0') * (num2[i] - '0'));
                tmp += n % 10 + '0';
                carry = n / 10;
            }
            if(carry != 0)
                tmp += carry + '0';
            int tmpp = num2.size() - 1 - i;
            reverse(tmp.begin(), tmp.end());
            while(tmpp != 0)
            {
                tmp += "0";
                tmpp--;
            }
            res = addTwoString(res, tmp);
        }
        return res;
    }
    string addTwoString(string s1, string s2)
    {
        int len1 = s1.length() - 1;
        int len2 = s2.length() - 1;
        int carry = 0;
        string tmp = "";
        while(len1 >= 0 && len2 >= 0)
        {
            int n = s1[len1] - '0' + s2[len2] - '0' + carry;
            carry = n / 10;
            tmp += n % 10 + '0';
            len1--;
            len2--;
        }
        while(len1 >= 0)
        {
            int n = s1[len1] - '0' + carry;
            carry = n / 10;
            tmp += n % 10 + '0';
            len1--;
        }
        while(len2 >= 0)
        {
            int n = s2[len2] - '0' + carry;
            carry = n / 10;
            tmp += n % 10 + '0';
            len2--;
        }
        if(carry != 0)
            tmp += carry + '0';
        reverse(tmp.begin(), tmp.end());
        return tmp;
    }
};
