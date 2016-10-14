class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0; int r = height.size() - 1;
        int res = 0;
        while(l < r)
        {
            int tmp = min(height[l], height[r]);
            res = max(res, (r - l) * min(height[l], height[r]));
            if (tmp == height[l])
                l++;
            else
                r--;
        }
        return res;
    }
};
    
// brute force
/* int maxArea(vector<int>& height) {
        int res = 0;
        if(height.size() == 0 || height.size() == 1)
            return 0;
        for(int i = 1; i < height.size(); i++)
        {
            int tmp_max = 0;
            for(int j = 0; j < i; j++)
                tmp_max = max(tmp_max, (i - j) * min(height[i], height[j]));
            res = max(res, tmp_max);
        }
        return res;
    }
*/
// I have two solutions for this question, the second is brute force and the first is learning from others. 
// The idea is simple, move the index that height[index] is smaller
