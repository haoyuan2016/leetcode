class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size();
        int n2 = version2.size();
        int i = 0;
        int j = 0;
        while(i < n1 || j < n2)
        {
            int d1 = 0, d2 = 0;
            while(i < n1 && version1[i] != '.')
            {
                d1 = d1 * 10 + version1[i] - '0';
                i++;
            }
            while(j < n2 && version2[j] != '.')
            {
                d2 = d2 * 10 + version2[j] - '0';
                j++;
            }
            if(d1 > d2) return 1;
            else if(d1 < d2) return -1;
            else
            {
                i++;
                j++;
            }
        }
        return 0;
    }
};
