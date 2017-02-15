class Solution {
public:
    Solution(vector<int> nums) {
        for(auto i : nums)
            vec.push_back(i);
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return vec;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res;
        for(auto i : vec)
            res.push_back(i);
        int n = vec.size();
        for(int i = 0; i < n; i++)
        {
            int tmp = rand() % (n - i);
            swap(res[i], res[i + tmp]);
        }
        return res;
    }
private:
    vector<int> vec;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
