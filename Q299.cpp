class Solution {
public:
    string getHint(string secret, string guess) {
        if(secret.size() != guess.size()) return NULL;
        int bull = 0;
        int cows = 0;
        unordered_map<char, int> m;
        for(auto i : secret)
            m[i]++;
        for(int i = 0; i < secret.size(); i++)
        {
            if(secret[i] == guess[i])
            {
                m[secret[i]]--;
                bull++;
            }
            else
            {
                if(m.find(guess[i]) != m.end())
                {
                        m[guess[i]]--;
                        cows++;
                }
            }
        }
        for(auto i : m)
            if(i.second < 0)
                cows += i.second;
        return to_string(bull) + "A" + to_string(cows) + "B";
    }
};
