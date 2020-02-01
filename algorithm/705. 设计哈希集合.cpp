class MyHashSet {
public:
    /** Initialize your data structure here. */
    int hashSize ;
    vector<int> hashTable ;
    MyHashSet() {
        hashSize = 1000000 + 10 ;
        hashTable = vector<int> (hashSize , 0) ;
    }
    
    void add(int key) {
        hashTable[key] = 1 ;
        return ;
    }
    
    void remove(int key) {
        hashTable[key] = 0 ;
        return ;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if (hashTable[key] != 0) {
            return true ;
        }
        return false ;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */