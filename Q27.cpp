// Simply use the idea in Q26.
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int update = (val)? 0 : 1;
        int i = 0;
        for(int j = 0; j < nums.size(); j++)
        {
            if(nums[j] == val) nums[j] = update;
            else
            {
                nums[i]= nums[j];
                i++;
            }
        }
        return i;
    }
};
