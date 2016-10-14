class Solution {
public:
    int myAtoi(string str) {
        long res = 0;
        int negative_sign = 1;
        int cur = 0;
        bool has_number = true;
        while(cur < str.length())
        {
            if(str[cur] == ' ' || str[cur] - '0' == 0)
            {
                cur++;
                continue;
            }
            else if(str[cur] == '-' || str[cur] == '+' || (str[cur] - '0' < 10 && str[cur] - '0' > 0))
            {
                negative_sign = (str[cur] == '-')? -1 : 1;
                if(str[cur] - '0' < 10 && str[cur] - '0' > 0)
                    res += str[cur] - '0';
                cur++;
                while(cur < str.length() && str[cur] - '0' < 10 && str[cur] - '0' >= 0)
                {
                    res = res * 10 + str[cur++] - '0';
                    if(negative_sign * res > INT_MAX) return INT_MAX;
                    if(negative_sign * res < INT_MIN) return INT_MIN;
                }
                return int(negative_sign * res);
            }
            else
                return 0;
        }
        return 0;
    }
};
// Note: One solution in leetcode discuss use find_first_not_of, like int i = s.find_first_not_of(' '), the return type is size_t
