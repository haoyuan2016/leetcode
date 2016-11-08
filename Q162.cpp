// My solution, time complexity O(N)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.empty()) return -1;
        if(nums.size() == 1) return 0;
        if(nums.size() >= 2)
        {
            if(nums[0] > nums[1]) return 0;
            if(nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size() - 1;
        }
        for(int i = 1; i < nums.size() - 1; i++)
        {
            if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                return i;
        }
        return -1;
    }
};

// Solution with time complexity Q(logN)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        while(l < r)
        {
            int mid = l + (r - l) / 2; 
            if(nums[mid] < nums[mid + 1])
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};
