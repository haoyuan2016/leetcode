class Solution {
public:
    string countAndSay(int n) {
        string res;
        if(n == 1)
            return "1";
        if(n == 2)
            return "11";
        res = "11";
        int cur = 2;
        while(cur < n)
        {
            string tmp = "";
            int nums = 1;
            for(int i = 1; i < res.size(); i++)
            {
                if(i == res.size() - 1)
                {
                    if(res[i] == res[i - 1])
                    {
                        tmp.push_back('0' + nums + 1);
                        tmp.push_back(res[i]); 
                    }
                    else
                    {
                        tmp.push_back('0' + nums);
                        tmp.push_back(res[i - 1]);
                        tmp.push_back('1');
                        tmp.push_back(res[i ]);
                    }
                }
                else if(res[i] == res[i - 1])
                    nums++;
                else // (res[i] != res[i - 1]) 
                {
                    tmp.push_back('0' + nums);
                    tmp.push_back(res[i - 1]);
                    nums = 1;
                }
            }
            res = tmp;
            cur++;
        }
        return res;
    }
};
