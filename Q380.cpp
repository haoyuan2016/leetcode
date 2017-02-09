//Note that int i = rand()& j  returns random from 0 to j - 1;
// We cannot access set by index[], but we can do auto it = s.begin(); advance(it, n) to move iterator. 
// We cannot use set<int> s; s.begin()++; which is wrong!
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(s.find(val) != s.end()) return false;
        s.insert(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(s.find(val) != s.end())
        {
                        s.erase(val);
            return true;
        }
        else
            return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int seed = rand() % s.size();
        auto it = s.begin();
        advance(it, seed);
        return *it;
    }
private:
    set<int> s;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
