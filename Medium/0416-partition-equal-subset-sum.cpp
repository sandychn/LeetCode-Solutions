template<typename T = int>
struct Bitset {
    T* arr;

    Bitset(int n) {
        size_t len = (n + sizeof(T) - 1) / sizeof(T);
        arr = new T[len];
        memset(arr, 0, len * sizeof(T));
    }

    ~Bitset() {
        delete[] arr;
        arr = nullptr;
    }

    bool get(size_t pos) const {
        size_t index = pos / sizeof(T);
        return (arr[index] >> (pos % sizeof(T))) & 1;
    }

    void set(size_t pos, bool val) {
        size_t index = pos / sizeof(T);
        arr[index] |= (static_cast<int>(val) << (pos % sizeof(T)));
    }

    void set(size_t pos, int val) {
        size_t index = pos / sizeof(T);
        arr[index] |= (val << (pos % sizeof(T)));
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        
        if (total % 2 != 0) return false;
        
        int target = total / 2;

        Bitset dp(target + 1);
        dp.set(0, 1);
        for (int val : nums) {
            for (int i = target; i >= val; i--) {
                dp.set(i, dp.get(i) | dp.get(i - val));
            }
        }
        return dp.get(target);
    }
};
