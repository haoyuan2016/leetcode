// Solution one:
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        wordList.insert(endWord);
        queue<string> q;
        q.push(beginWord);
        wordList.erase(beginWord);
        int distance = 1;
        while(!q.empty())
        {
            distance++;
            int n = q.size();
            int cur = 0;
            while(cur < n)
            {
                cur++;
                string tmp = q.front();
                q.pop();
                if(isNeighbour(tmp, endWord)) return distance;
                vector<string> visited;
                for(string a : wordList)
                {
                    if(isNeighbour(a, tmp))
                    {
                        q.push(a);
                        visited.push_back(a);
                    }
                }
                while(!visited.empty())
                {
                    wordList.erase(visited.back());
                    visited.pop_back();
                }
            }
        }
        return 0;
    }
    bool isNeighbour(string a, string b)
    {
        int cur = 0;
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] != b[i]) cur++;
            if(cur == 2) return false;
        }
        return true;
    }
};
// Solution two:
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        wordList.insert(endWord);
        queue<string> q;
        q.push(beginWord);
        wordList.erase(beginWord);
        int distance = 1;
        while(!q.empty())
        {
            int n = q.size();
            int cur = 0;
            distance++;
            while(cur < n)
            {
                cur++;
                string tmp = q.front();
                q.pop();
                if(isNeighbour(tmp, endWord)) return distance;
                for(int i = 0; i < tmp.size(); i++)
                {
                    for(char j = 'a'; j < 'a' + 26; j++)
                    {
                        char cc = tmp[i];
                        tmp[i] = j;
                        if(wordList.find(tmp) != wordList.end())
                        {
                            q.push(tmp);
                            wordList.erase(tmp);
                        }
                        tmp[i] = cc;
                    }
                }
            }
        }
        return 0;
    }
    bool isNeighbour(string a, string b)
    {
        int cur = 0;
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] != b[i]) cur++;
            if(cur == 2) return false;
        }
        return true;
    }
};
