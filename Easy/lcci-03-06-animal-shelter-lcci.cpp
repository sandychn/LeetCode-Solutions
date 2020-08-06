template<size_t size, typename T>
class Queue {
private:
    T que[size];
    int head, tail, siz;

public:
    Queue(): head(0), tail(0), siz(0) {}

    T front() { return que[head]; }

    void push(T val) {
        que[tail] = val, tail = (tail + 1) % size;
        ++siz;
    }

    void pop() {
        head = (head + 1) % size;
        --siz;
    }

    bool empty() { return siz == 0; }
};

class AnimalShelf {
public:
    AnimalShelf() {
        
    }
    
    void enqueue(vector<int> animal) {
        lst[animal[1]].push(animal[0]);
    }
    
    vector<int> dequeueAny() {
        const vector<int>& res0(peek(0));
        const vector<int>& res1(peek(1));
        if (res0[1] == -1 || res1[1] == -1) {
            if (res0[1] != -1) {
                lst[0].pop();
                return res0;
            }
            if (res1[1] != -1) {
                lst[1].pop();
                return res1;
            }
            return {-1, -1};
        }
        if (res0[0] < res1[0]) {
            lst[0].pop();
            return res0;
        }
        lst[1].pop();
        return res1;
    }
    
    vector<int> dequeueDog() {
        return deque(1);
    }
    
    vector<int> dequeueCat() {
        return deque(0);
    }

private:
    Queue<20000, int> lst[2];

    inline vector<int> deque(int id) {
        const vector<int>& res(peek(id));
        if (res[1] != -1) lst[id].pop();
        return res;
    }

    inline vector<int> peek(int id) {
        return lst[id].empty() ? vector<int>{-1, -1} : vector<int>{lst[id].front(), id};
    }
};

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */
