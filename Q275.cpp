class Solution {
public:
    int hIndex(vector<int>& citations) {
        int res = 0;
        int n = citations.size();
        int tmp = 1;
        for(int i = n - 1; i >= 0; i--)
        {
            if(citations[i] >= tmp)
            {
                res++;
                tmp++;
            }
            else
                return res;
        }
        return res;
    }
};
