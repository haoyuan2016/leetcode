// Solution one:
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int n = nums.size();
        if(n == 1 || n == 2)
            return n;
        for(int i = 2; i < nums.size();)
        {
            if(nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2])
                nums.erase(nums.begin() + i);
            else
                i++;
        }
        return nums.size();
    }
};
