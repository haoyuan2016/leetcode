class Solution {
public:
    bool isAdditiveNumber(string num) {
        if(num.empty()) return false;
        int n = num.size();
        for(int i = 1; i <= n / 2; i++)
            for(int j = 1; i + j <= 2 * n / 3 + 1; j++)
            {
                if(num[0] == '0' && i != 1) continue;
                if((num[i] == '0' && j != 1) || num[i + j] == '0') continue;
                long long a1= stoll(num.substr(0, i));
                long long a2 = stoll(num.substr(i, j));
                string cur = num.substr(0, i + j) + to_string(a1 + a2);
                while(cur.size() < num.size())
                {
                    long long next = a1 + a2;
                    a1 = a2;
                    a2 = next;
                    cur += to_string(a1 + a2);
                }
                if(cur == num) return true;
            }
        return false;
    }

};
