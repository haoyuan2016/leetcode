class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> s1;
        unordered_set<int> s2;
        for(auto i : nums1)
            s1.insert(i);
        for(auto i : nums2)
        {
            if(s1.find(i) != s1.end() && s2.find(i) == s2.end())
            {
                res.push_back(i);
                s2.insert(i);
            }
                
        }
        return res;
    }
};
