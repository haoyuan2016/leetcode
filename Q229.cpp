// see https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html
// We need two pass, the first pass find the possible majority candidates, the second double check the correctness of the candidates.
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.empty()) return vector<int>{};
        vector<int> res;
        int major1, major2 = 0, count1 = 0, count2 = 0;
        major1 = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == major1)
                count1++;
            else if(nums[i] == major2)
                count2++;
            else if(count1 == 0)
            {
                major1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0)
            {
                major2 = nums[i];
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        int s1 = 0, s2 = 0;
        for(auto a : nums)
        {
            if(a == major1)
                s1++;
            else if(a == major2)
                s2++;
        }
        if(s1 > nums.size() / 3)
            res.push_back(major1);
        if(s2 > nums.size() / 3)
            res.push_back(major2);
        return res;
    }
};
