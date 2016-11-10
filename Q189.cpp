// Another solution is to reverse three times;
// 1234567 with n = 7, k = 3
// reversr and obtain 1234 765
// reverse and obtain 4321 765
// reverse and obtain 567 1234
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
