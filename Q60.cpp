// My first thought is to obtain all the permutations denoted as holder, and then get the (k - 1)-th element in holder.
// It does not work, because the element stored in holder is not in alphabet order.
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<string> holder;
        int a = 1;
        string tmp = "";
        while(a <= n)
        {
            tmp += a + '0';
            a++;
        }
        helper(holder, tmp, n, 0);
        return holder[k - 1];
    }
    void helper(vector<string>& holder, string tmp, int n, int cur)
    {
        if(cur == n)
        {
            holder.push_back(tmp);
            return;
        }
        for(int i = cur; i < n; i++)
        {
            swap(tmp[i], tmp[cur]);
            helper(holder, tmp, n, cur + 1);
            swap(tmp[i], tmp[cur]);
        }
    }
};
// Solution two
class Solution {
public:
    string getPermutation(int n, int k) {
        if(n == 1)
            return "1";
        string left = "";
        int a = 1, e = 1;
        while(a <= n)
        {
            left.push_back(a + '0');
            e = e * a;
            a++;
        }
        a--;
        e = e / a;
        string res = "";
        while(k > 0)
        {
            int tmp = (k - 1) / e; // First round: tmp = 1;
            res.push_back(left[tmp]);
            left.erase(left.begin() + tmp);
            k = k % e;        // k = 2;   k = 1;
            e = e / (a - 1);  // e = 2;   e = 1;
            a--;              // a = 3;   a = 2;
        }
        if (k == 0)
            reverse(left.begin(), left.end());
        return res + left;
    }
};
