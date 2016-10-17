// My code
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i = 0; i < (int)nums.size() - 1; i++)
        {
            while(i < (int)nums.size() - 1 && nums[i] == nums[i + 1])
                nums.erase(nums.begin() + i + 1);
        }
        return nums.size();
    }
};
// Learn to use erase in vector. erase can only be used to iterator.
// vector<int>::iterator
// Reffering to https://discuss.leetcode.com/topic/17252/5-lines-c-java-nicer-loops, actually we do not need to erase anything.
