// Solution one:
// Note digits.isert(digits.begin(), val), iterator insert (iterator position, const value_type& val);
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty())
            return digits;
        int n = digits.size();
        int carry = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            int tmp;
            if(i == n - 1)
                tmp = carry + digits[i] + 1;
            else
                tmp = carry + digits[i];
            if(tmp < 10)
            {
                digits[i] = tmp;
                return digits;
            }
            else if(tmp >= 10)
            {
                digits[i] = tmp % 10;
                carry = 1;
            }
        }
        if(carry = 1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
