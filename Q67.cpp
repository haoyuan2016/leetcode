class Solution {
public:
    string addBinary(string a, string b) {
        int lenA = a.length(), lenB = b.length();
        string res = "";
        int carry = 0;
        while(lenA > 0 && lenB > 0)
        {
            int n = a[lenA - 1] - '0' + b[lenB - 1] - '0' + carry;
            carry = n / 2;
            res.push_back(n % 2 + '0');
            lenA--;
            lenB--;
        }
        while(lenA > 0)
        {
            int n = a[lenA - 1] - '0' + carry;
            carry = n / 2;
            res.push_back(n % 2 + '0');
            lenA--;
        }
        while(lenB > 0)
        {
            int n = b[lenB - 1] - '0' + carry;
            carry = n / 2;
            res.push_back(n % 2 + '0');
            lenB--;
        }
        if(carry == 1)
        res += "1";
        reverse(res.begin(), res.end());
        return res;
    }
};
