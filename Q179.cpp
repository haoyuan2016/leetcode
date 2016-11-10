// There are two ways to write the compare function.
// 1) write a struct called myfunc, but in sort(s.begin(), s.end(), myfunc()), we need to write myfunc();
// 2) write like this
// bool myfunc(string a, string b){
//      return a + b > b + a;
// }
// but here, in in sort(s.begin(), s.end(), myfunc), we do not need the "()"; Also in a class, we need to add static before bool
// that is
// static bool myfunc(string a, string b){}
class Solution {
public:
    struct myfunc
    {
        bool operator () (string a, string b) {
            return a + b > b + a;
        }
    };
    string largestNumber(vector<int>& nums) {
        string res = "";
        vector<string> s;
        for(int i = 0; i < nums.size(); i++)
            s.push_back(to_string(nums[i]));
        sort(s.begin(), s.end(), myfunc());
        for(auto a : s)
            res += a;
        if(res.find_first_not_of('0') != string::npos)
        {
            int index = res.find_first_not_of('0');
            return res.substr(index);
        }
        else 
            return "0";
    }
};
