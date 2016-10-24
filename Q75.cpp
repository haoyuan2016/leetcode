class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.empty())
            return;
        int n = nums.size();
        int start = 0;
        bool isStart = false;
        int finish = n - 1;
        int cur = 0;
        while(cur <= finish)
        {
            if (nums[cur] == 0 && isStart)
            {
                swap(nums[cur], nums[start]);
                start++;
            }
            else if(nums[cur] == 1 && !isStart)
            {
                start = cur;
                isStart = true;
            }
            else if(nums[cur] == 2) 
            {
                swap(nums[cur], nums[finish]);
                finish--;
                continue;
            }
            cur++;
        }
        return;
    }
};
