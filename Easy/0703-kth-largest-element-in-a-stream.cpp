class KthLargest {
public:
    KthLargest(int k, vector<int>& nums): k(k) {
        for_each(nums.begin(), nums.end(), bind(&KthLargest::add, this, placeholders::_1));
    }
    
    int add(int val) {
        heap.push(val);
        while (static_cast<int>(heap.size()) > k) heap.pop();
        return heap.top();
    }

private:
    int k;
    priority_queue<int, vector<int>, greater<int>> heap;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
