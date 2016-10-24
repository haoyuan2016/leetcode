class Solution {
public:
    string simplifyPath(string path) {
        string tmp, s;
        stringstream ss(path);
        vector<string> str;
        while(getline(ss, tmp, '/'))
        {
            if(tmp == "" || tmp == ".") continue;
            if(tmp == ".." && !str.empty()) str.pop_back();
            else if(tmp != "..") str.push_back(tmp);
        }
        string res = "";
        for(string a : str)
        res += "/" + a;
        return (res == "")? "/" : res;
    }
};
