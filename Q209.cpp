class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int window_size = 0;
        int curSum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(window_size > 0)
                curSum = curSum + nums[i] - nums[i - window_size];
            else
                curSum += nums[i];
            if(curSum >= s) // find window
            {
                if(window_size == 0)
                    window_size = i + 1;
                while(curSum >= s) // shrink
                {
                    if(curSum - nums[i - window_size + 1] >= s)
                    {
                        curSum = curSum - nums[i - window_size + 1];
                        window_size--;
                    }
                    else break;
                }
            }
        }
        return window_size;
    }
};
