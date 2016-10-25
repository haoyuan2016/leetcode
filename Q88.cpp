class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(nums1.size() > m)
            nums1.pop_back();
        while(nums2.size() > n)
            nums2.pop_back();
        int ptr1 = 0;
        int ptr2 = 0;
        while(ptr1 < m && ptr2 < n)
        {
            if(nums1[ptr1] < nums2[ptr2])
                ptr1++;
            else if(nums1[ptr1] >= nums2[ptr2])
            {
                nums1.insert(nums1.begin() + ptr1, nums2[ptr2]);
                ptr1++;
                ptr2++;
                m++;
            }
        }
        while(ptr2 < n)
        {
            nums1.push_back(nums2[ptr2]);
            ptr2++;
        }
    }
};
