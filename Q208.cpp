class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode* next[26];
	bool isWord;
	TrieNode() {
		isWord = false;
		for (auto &a : next)
			a = NULL;
	}
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}
	// Inserts a word into the trie.
	void insert(string word) {
		int tmp = 1;
		TrieNode* ptr = root;
		for (int i = 0; i < word.size(); i++)
		{
			if (ptr->next[word[i] - 'a'])
				ptr = ptr->next[word[i] - 'a'];
			else
			{
				TrieNode* tmp = new TrieNode();
				ptr->next[word[i] - 'a'] = tmp;
				ptr = tmp;
			}
			if (i == word.size() - 1)
				ptr->isWord = true;
		}
	}
	bool search(string word) {
		if (word.empty()) return true;
		TrieNode* ptr = root;
		for (int i = 0; i < word.size(); i++)
		{
			if (ptr->next[word[i] - 'a'])
				ptr = ptr->next[word[i] - 'a'];
			else
				return false;
			if (i == word.size() - 1)
				if (ptr->isWord == false)
					return false;
		}
		return true;
	}
	bool startsWith(string prefix) {
		TrieNode* ptr = root;
		for (int i = 0; i < prefix.size(); i++)
		{
			if (ptr->next[prefix[i] - 'a'])
				ptr = ptr->next[prefix[i] - 'a'];
			else
				return false;
			if (i == prefix.size())
			if (ptr->isWord == true) return false;
		}
		return true;
	}
private:
	TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
