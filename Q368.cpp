// The key is to design the DP, where T[n] stands for the length of the longest subsequence ended with nums[n];
// Another key is that, if we can addd one more element to add an existing subsequence, we need to guarantee that the added one % the largeest == 0.
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.empty()) return vector<int>();
        int n = nums.size();
        if(n == 1) return nums;
        sort(nums.begin(), nums.end());
        vector<int> T(n, 1);
        vector<int> parent(n, 0);
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                int localMax = 0;
                if(nums[i] % nums[j] == 0 && T[i] < T[j] + 1)
                {
                     T[i] = T[j] + 1;
                     parent[i] = j;
                }
            }
        }
		vector<int> res;
		int resMax = 0;
		int index = 0;
		for (int i = 0; i < n; i++)
		{
			if (T[i] > resMax)
			{
				resMax = T[i];
				index = i;
			}
		}
		int tmp = T[index];
		while (tmp)
		{
			res.push_back(nums[index]);
			index = parent[index];
			tmp--;
		}
		reverse(res.begin(), res.end());
		return res;
    }
};
