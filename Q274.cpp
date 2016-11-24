// O(N^2) solution.
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty()) return 0;
        int n = citations.size();
        vector<int> vec(n + 1, 0);
        for(int i = 0; i < n; i++)
        {
            int tmp = min(citations[i], n);
            while(tmp >= 0)
            {
                vec[tmp]++;
                tmp--;
            }
        }
        for(int i = n; i >= 0; i--)
        {
            if(vec[i] >= i)
                return i;
        }
        return 0;
    }
};
// O(N) solution.
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty()) return 0;
        int n = citations.size();
        vector<int> vec(n + 1, 0);
        for(int i = 0; i < n; i++)
        {
            if(citations[i] >= n)
                vec[n]++;
            else
                vec[citations[i]]++;
        }
        int t = 0;
        for(int i = n; i >= 0; i--)
        {
            t = t + vec[i];
            if(i <= t)
                return i;
        }
        return 0;
    }
};
