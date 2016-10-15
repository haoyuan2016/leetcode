class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.empty())
            return vector<vector<int>>{};
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < len - 3; i++)
        {
            if(i != 0 && nums[i] == nums[i - 1])
                continue;
            for(int j = i + 1; j < len - 2; j++)
            {
                if(j != i + 1 && nums[j] == nums[j - 1])
                    continue;
                int target1 = target - nums[i] - nums[j];
                int m = j + 1; int n = len - 1;
                while(m < n)
                {
                    if(nums[m] + nums[n] < target1)
                        m++;
                    else if(nums[m] + nums[n] > target1)
                        n--;
                    else if(m != j + 1 && nums[m] == nums[m - 1])
                        m++;
                    else if(n != len - 1 && nums[n] == nums[n + 1])
                        n--;
                    else
                    {
                        res.push_back(vector<int>{nums[i],nums[j],nums[m], nums[n]});
                        int k = m + 1;
                        while(k < n && nums[k] == nums[m])
                            k++;
                        m = k;
                        int l = n - 1;
                        while(k > m && nums[l] == nums[n])
                            l--;
                        n = l;
                    }
                }
            }
        }
        return res;
    }
};
// note: we have to have two ints, k and l to fast calculate the equal values in nums. Otherwise it times out.
