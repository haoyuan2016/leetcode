class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.empty()) return true;
        istringstream ss(preorder);
        string token;
        stack<string> s;
        while(getline(ss, token, ','))
        {
            if(token != "#") s.push(token);
            else
            {
                if(!s.empty() && s.top() != "#")
                    s.push("#");
                else // s.top() == '#'
                {
                    s.push("#");
                    while(true)
                    {
                        string c1, c2, c3;
                        c1 = s.top();
                        s.pop();
                        if(!s.empty())
                        {
                            c2 = s.top();
                            s.pop();
                        }
                        else
                        {
                            s.push(c1);
                            break;
                        }
                        if(!s.empty())
                        {
                            c3 = s.top();
                            s.pop();
                        }
                        else
                        {
                            s.push(c2);
                            s.push(c1);
                            break;
                        }
                        if(c1 == "#" && c2 == "#" && c3 != "#")
                            s.push("#");
                        else
                        {
                            s.push(c3);
                            s.push(c2);
                            s.push(c1);
                            break;
                        }
                    }
                }
            }
        }
        if(!s.empty() && s.size() == 1 && s.top() == "#") return true;
        return false;
    }
};
