// solution one with extra space, and O(NlongN)
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mid = (n - 1) / 2;
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 0)
                res[i] = nums[mid - i / 2];
            else
            {
                res[i] = nums[n - 1 - i / 2];
            }
        }
        for(int i = 0; i < n; i++)
            nums[i] = res[i];
    }
};
