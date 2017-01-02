class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int numbersOfZeros = 0;
        int tmpIndex = 0;
        int n = nums.size();
        int i = 0;
        for(; i < n; i++)
        {
            if(nums[i] == 0)
            {
                numbersOfZeros++;
                continue;
            }
            else
            {
                nums[tmpIndex] = nums[i];
                tmpIndex++;
            }
        }
        for(i = n - numbersOfZeros; i < n; i++)
            nums[i] = 0;
    }
};
