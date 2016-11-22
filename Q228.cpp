class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty()) return vector<string>{};
        vector<string> res;
        if(nums.size() == 1)
        {
            res.push_back(to_string(nums[0]));
            return res;
        }
        int start = nums[0];
        int finish= nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(i == (int)nums.size() - 1)
            {
                if(nums[i] - nums[i - 1] == 1)
                {
                    finish++;
                    string tmp = to_string(start) + "->" + to_string(finish);
                    res.push_back(tmp);
                }
                else
                {
                    if(start == finish)
                        res.push_back(to_string(start));
                    else
                    {
                        string tmp = to_string(start) + "->" + to_string(finish);
                        res.push_back(tmp);
                    }
                    res.push_back(to_string(nums[i]));
                }
                break;
            }
            else if(nums[i] - nums[i - 1] == 1)
                finish++;
            else
            {
                if(start != finish)
                {
                    string tmp = to_string(start) + "->" + to_string(finish);
                    res.push_back(tmp);
                    start = nums[i];
                    finish = nums[i];
                }
                else
                {
                    res.push_back(to_string(start));
                    start = nums[i];
                    finish = nums[i];
                }

            }
        }
        return res;
    }
};
