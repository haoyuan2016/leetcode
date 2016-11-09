// Solution one
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++)
            m[nums[i]]++;
        int res;
        int times = INT_MIN;
        
        for(auto a : m)
            if(a.second > times)
            {
                res = a.first;
                times = a.second;
            }
        return res;
    }
};
// Solution two
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            m[nums[i]]++;
            if(m[nums[i]] > n / 2)
                return nums[i];
        }
        return -1;
    }
};
// Solution three, with contant space
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0], count = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(count == 0)
            {
                major = nums[i];
                count = 1;
            }
            else if(nums[i] == major)
                count++;
            else
                count--;
        }
        return major;
    }
};
