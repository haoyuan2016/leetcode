// Solution one: incredible slow.
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        for(int i = 0; i < numbers.size(); i++)
        {
            if(numbers[i] > target / 2) return res;
            int tmp = isfind(numbers, target - numbers[i], i + 1);
            if(tmp != 0)
            {
                res.push_back(i + 1);
                res.push_back(tmp + 1);
                return res;
            }
        }
        return res;
    }
    int isfind(vector<int> nums, int target, int cur)
    {
        int l = cur;
        int r = nums.size();
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return 0;
    }
};
// Solution two:
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        vector<int> res;
        while(l < r)
        {
            while(numbers[l] + numbers[r] > target)
                r--;
            while(numbers[l] + numbers[r] < target)
                l++;
            if(numbers[l] + numbers[r] == target)
            {
                res.push_back(l + 1);
                res.push_back(r + 1);
                return res;
            }
        }
        return res;
        
    }
};
