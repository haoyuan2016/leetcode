// Note that long is at least 32 bit, long long is at least 64 bit.
// In this question, the tricky part is a lot: 1) we use map<key, value>, where key is the remainder, and value is the position where
// we should insert "(". 2) When we use insert in a string, we can use both s.insert(pos, string) or s.insert(pos, 1, char); 3) There are
// a lot of special cases, like 4) we need the consider the sign, we can use if(numerator < 0 ^ denominator < 0) res += "-", but first need 
// to check if(numerator == 0) return "0"; otherwise we cannot pass the case {0, -1}.

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(denominator == 0) return "";
        if(numerator == 0) return "0";
        string res = "";
        if(numerator < 0 ^ denominator < 0) res += "-";
        long n = labs(numerator);
        long d = labs(denominator);
        res += to_string(n / d);
        long r = n % d;
        if(r == 0) return res;
        map<int, int> m;
        res += ".";
        while(r != 0)
        {
            if(m.find(r) != m.end())
            {
                res.insert(m[r], "(");
                res.push_back(')');
                break;
            }
            m[r] = res.size();
            r = r * 10;
            res += to_string(r / d);
            r = r % d;
        }
        return res;
    }
};
