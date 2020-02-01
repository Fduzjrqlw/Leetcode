class MyHashMap {
public:
    /** Initialize your data structure here. */
    bool hashTable[1000000 + 10] ;
    int valueTable[1000000 + 10] ;
    MyHashMap() {
        memset(hashTable , false , sizeof(hashTable)) ;
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        hashTable[key] = true ;
        valueTable[key] = value ;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        if (hashTable[key]) {
            return valueTable[key] ;
        }
        return -1 ;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        hashTable[key] = false ;
        return ;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */