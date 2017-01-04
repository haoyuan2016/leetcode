// note that if((bitOper[i] & bitOper[j]) == 0) but not if(bitOper[i] & bitOper[j] == 0)
class Solution {
public:
    int maxProduct(vector<string>& words) {
        if(words.empty()) return 0;
        int res = 0;
        int n = words.size();
        vector<int> bitOper(n, 0);
        for(int i = 0; i < n; i++)
           for(int j = 0; j < words[i].size(); j++)
               bitOper[i] = bitOper[i] | (1 << (words[i][j] - 'a'));
        for(int i = 0; i < words.size() - 1; i++)
            for(int j = i + 1; j < words.size(); j++)
                if((bitOper[i] & bitOper[j]) == 0)
                    res = max(res, (int)words[i].size() * (int)words[j].size());
        return res;
    }

};
