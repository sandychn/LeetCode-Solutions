const int M = 769;

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {

    }
    
    void add(int key) {
        if (!contains(key)) lst[hashCode(key)].push_front(key);
    }
    
    void remove(int key) {
        lst[hashCode(key)].remove(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int code = hashCode(key);
        return find(lst[code].begin(), lst[code].end(), key) != lst[code].end();
    }

private:
    forward_list<int> lst[M];
    
    int hashCode(int x) {
        return x % M;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
