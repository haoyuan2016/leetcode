class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> um;
        for(auto i : magazine)
            um[i]++;
        for(auto i : ransomNote)
        {
            if(um.find(i) == um.end()) return false;
            um[i]--;
            if(um[i] < 0) return false;
        }
        return true;
    }
};
