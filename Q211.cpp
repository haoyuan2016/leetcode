class WordDictionary {
public:
    struct TrieNode
    {
        TrieNode* next[26];
        bool isWord;
        TrieNode(){
            isWord = false;
            for(auto &a : next)
                a = NULL;
        }
    };
    WordDictionary()
    {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* ptr = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(ptr->next[word[i] - 'a'])
                ptr = ptr->next[word[i] - 'a'];
            else
            {
                TrieNode* tmp = new TrieNode();
                ptr->next[word[i] - 'a'] = tmp;
                ptr = tmp;
            }
        }
        ptr->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word)
    {
        return mySearch(word, root);
    }
    bool mySearch(string word, TrieNode* root) {
        TrieNode* ptr = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(word[i] != '.')
            {
                if(ptr->next[word[i] - 'a'])
                    ptr = ptr->next[word[i] - 'a'];
                else return false;
            }
            else // word[i] == '.'
            {
                for(auto a : ptr->next)
                {
					if (i == word.size() - 1)
					{
						if (a && a->isWord)
							return true;
					}
                    else if(a && mySearch(word.substr(i + 1), a))
                        return true;
                }
                return false;
            }
        }
        if(ptr->isWord == true) return true;
        return false;
    }
private:
    TrieNode* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
