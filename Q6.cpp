class Solution {
public:
    string convert(string s, int numRows) {
        if(s.empty())
            return "";
        if (numRows == 1 || s.length() == 1)
            return s;
        string res;
        int cur_line = 1;
        int start = 0;            
	    while (cur_line <= numRows && res.length() < s.length())
	    {
		    int tmp = start;
		    res += s[tmp];
		    if(numRows == cur_line)
            {
                while(tmp + 2 * (numRows - 1) < s.length())
                {
                    tmp = tmp + 2* (numRows - 1);
                    res += s[tmp];
                }
                break;
            }
		    while (tmp + 2 * (numRows - cur_line) < s.length())
		    {
		    	tmp = tmp + 2 * (numRows - cur_line);
		    	res += s[tmp];
		    	if (cur_line > 1 && tmp + 2 * (cur_line - 1) < s.length())
		    	{
		    		tmp = tmp + 2 * (cur_line - 1);
		    		res += s[tmp];
		    	}	
		    	else 
		    		tmp = tmp + 2 * (cur_line - 1);
		    }
		    cur_line++;
		    start++;
	    }
	return res;
        return res;
    }
};
