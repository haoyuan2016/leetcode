class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.empty()) return;
        int n = nums.size();
        k = k % n;
        vector<int> store;
        int cur = n - k;
        while(cur < n)
        {
            store.push_back(nums[cur]);
            cur++;
        }
        int tmp = n - 1;
        while(tmp >= k)
        {
            nums[tmp] = nums[tmp - k];
            tmp--;
        }
        for(int i = 0; i < store.size(); i++)
            nums[i] = store[i];
        return;
    }
};
