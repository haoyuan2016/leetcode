// Solution one with O(N) space and O(N) time.
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> s1;
        vector<int> s2;
        int n = nums.size();
        int tmp = 1;
        s1.push_back(tmp);
        for(int i = 0; i < n - 1; i++)
        {
            tmp = tmp * nums[i];
            s1.push_back(tmp);
        }
        tmp = 1;
        s2.push_back(tmp);
        for(int i = n - 1; i > 0; i--)
        {
            tmp = tmp * nums[i];
            s2.push_back(tmp);
        }
        vector<int> output;
        
        for(int i = 0; i < nums.size(); i++)
        {
            output.push_back(s1[i] * s2[n - 1 - i]);
        }
        return output;
    }
};
