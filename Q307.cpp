// Solution one, timeout
// see the data struct segement tree, which is suitable to maintain and calculate the sum in range(i,j) with complexity O(logN);
// https://zh.wikipedia.org/wiki/%E6%A0%91%E7%8A%B6%E6%95%B0%E7%BB%84

class NumArray {
private:
    vector<int> dp;
    vector<int> ups;
    vector<int> store;
public:
    NumArray(vector<int> &nums) {
        if(nums.empty()) return;
        int n = nums.size();
        dp.resize(n, 0);
        ups.resize(n, 0);
        store.resize(n, 0);
        for(int i = 0; i < n; i++)
            store[i] = nums[i];
        dp[0] = nums[0];
        for(int i = 1; i < n; i++)
            dp[i] = dp[i - 1] + nums[i];
    }
    void update(int i, int val) {
        ups[i] = store[i] - val;
    }

    int sumRange(int i, int j) {
        int res = 0;
        for(int t = i; t <=j; t++)
            res += ups[t];
        if(i == 0) return dp[j] - res;
        else return dp[j] - dp[i - 1] - res;
    }
};
