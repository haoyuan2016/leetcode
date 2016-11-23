class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.empty()) return -1;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(nums[n - 1] == n - 1) return n;
        int l = 0;
        int r = n - 1;
        while(l < r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] == mid)
                l = mid + 1;
            else
                r = mid;
        }
        return nums[r] - 1;
    }
};
// Solutoin two:
// See https://discuss.leetcode.com/topic/23427/3-different-ideas-xor-sum-binary-search-java-code
// It is clever to let r = n, not r = n - 1;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.empty()) return -1;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int r = n;
        while(l < r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] > mid)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
