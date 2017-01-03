class NumArray {
private:
    vector<int> dp;
public:
    NumArray(vector<int> &nums) {
        if(nums.empty()) return;
        dp.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++)
            dp.push_back(nums[i] + dp[i - 1]);
    }

    int sumRange(int i, int j) {
        if(i == 0) return dp[j];
        else return dp[j] - dp[i - 1];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
