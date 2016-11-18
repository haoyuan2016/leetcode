class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.empty() || k < 1 || t < 0) return false;
        set<int> window;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > k) window.erase(nums[i - k - 1]);
            auto pos = window.lower_bound(nums[i] - t);
            if(pos != window.end() && *pos - t <= nums[i]) return true;
            window.insert(nums[i]);
        }
        return false;
    }
};

// window.lower_bound(nums[i] - t), which is to find the first iterator that not smaller than (nums[i] - t);
