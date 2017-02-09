// solution one: a naive one
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> holder;
        for(auto i : matrix)
            for(auto j : i)
                holder.push_back(j);
        sort(holder.begin(), holder.end());
        return holder[k - 1];
    }
};
