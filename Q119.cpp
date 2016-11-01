class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex < 0) return vector<int>{};
        if(rowIndex == 0) return vector<int>{1};
        vector<int> res(rowIndex + 1, 1);
        int cur = 1;
        while(cur <= rowIndex)
        {
            int mid = cur / 2;
            for(int i = mid; i >= 1; i--)
            {
                if(cur % 2 == 0 && i == mid)
                    res[i] = 2 * res[i - 1];
                else
                    res[i] = res[i] + res[i - 1];
            }
            cur++;
        }
        for(int i = rowIndex; i > rowIndex / 2; i--)
            res[i] = res[rowIndex - i];
        return res;
    }
};
