// I write a code that cannot slove the unique issue.
// If I use a set to filter the result, then it cause time out. The attached is my code without "unique" property
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> container;
        helper(res, container, nums, 0);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& container, vector<int> nums, int cur)
    {
        if(container.size() == 3)
        {
            if(container[0] + container[1] + container[2] == 0)
                res.push_back(container);
            return;
        }
        for(int i = cur; i < nums.size(); i++)
        {
            container.push_back(nums[i]);
            helper(res, container, nums, i + 1);
            container.pop_back();
        }
    }
};

// Acturally we do not need the recurive solution, simply brute force it. The code is as attached.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            if(i != 0 && nums[i] == nums[i - 1])
                continue;
            int target = 0 - nums[i];
            int j = i + 1; int k = nums.size() - 1;
            while(j < k)
            {
                vector<int> container;
                if(j != i + 1 && nums[j] == nums[j - 1])
                {
                    j++;
                    continue;
                }
                else if(k != nums.size() - 1 && nums[k] == nums[k + 1])
                {
                    k--;
                    continue;
                }
                else if(nums[j] + nums[k] == target)
                {
                    container.push_back(nums[i]);
                    container.push_back(nums[j]);
                    container.push_back(nums[k]);
                    res.push_back(container);
                    j++;
                    k--;
                }
                else if(nums[j] + nums[k] + nums[i] < 0)
                    j++;
                else
                    k--;
            }
        }
        return res;
    }
};
