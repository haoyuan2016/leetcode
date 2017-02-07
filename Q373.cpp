class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        if (nums1.empty() || nums2.empty() || k <= 0)
            return res;
        auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        pq.push(make_pair(0, 0));
        int n = nums1.size();
        int m = nums2.size();
        while(k > 0 && !pq.empty())
        {
            k--;
            auto a = pq.top();
            res.push_back(make_pair(nums1[a.first], nums2[a.second]));
            pq.pop();
            if(a.first + 1 < n)
                pq.push(make_pair(a.first + 1, a.second));
            if(a.first == 0 && a.second + 1 < m)
                pq.push(make_pair(a.first, a.second + 1));
        }
        return res;
    }
};
