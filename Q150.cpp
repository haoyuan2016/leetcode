class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty()) return 0;
        stack<int> s;
        for(int i = 0; i < tokens.size(); i++)
        {
            if(tokens[i] != "*" && tokens[i] != "/" && tokens[i] != "+" && tokens[i] != "-")
                s.push(stoi(tokens[i]));
            else
            {
                if(s.empty()) return -1;
                else
                {
                    int num1 = s.top();
                    s.pop();
                    if(s.empty()) return -1;
                    int num2 = s.top();
                    s.pop();
                    if(tokens[i] == "*")
                        s.push(num2 * num1);
                    else if(tokens[i] == "/")
                    {
                        if(num1 == 0)
                            return -1;
                        else
                            s.push(num2 / num1);
                    }
                    else if(tokens[i] == "+")
                        s.push(num2 + num1);
                    else if(tokens[i] == "-")
                        s.push(num2 - num1);
                    else
                        return -1;
                }
            }
        }
        int res = s.top();
        s.pop();
        if(s.empty()) return res;
        else return -1;
    }
};
