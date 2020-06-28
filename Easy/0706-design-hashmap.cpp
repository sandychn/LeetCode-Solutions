const int M = 769;

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {

    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int code = hashCode(key);
        auto it = find_if(lst[code].begin(), lst[code].end(), [key](const pair<int, int>& p) {
            return p.first == key;
        });
        if (it != lst[code].end()) {
            it->second = value;
        } else {
            lst[code].emplace_front(key, value);
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int code = hashCode(key);
        auto it = find_if(lst[code].begin(), lst[code].end(), [key](const pair<int, int>& p) {
            return p.first == key;
        });
        if (it != lst[code].end()) {
            return it->second;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        lst[hashCode(key)].remove_if([key](const pair<int, int>& p) {
            return p.first == key;
        });
    }

private:
    forward_list<pair<int, int>> lst[M];
    
    int hashCode(int x) {
        return x % M;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
