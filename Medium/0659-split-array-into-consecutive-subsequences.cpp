class Solution {
public:
    struct Node {
        int cnt[5];

        Node(): cnt() {}

        int findMin() const {
            for (int i = 1; i <= 4; i++) {
                if (cnt[i]) return i;
            }
            return -1;
        }

        int empty() const {
            return findMin() == -1;
        }
    };

    bool isPossible(vector<int>& nums) {
        if (nums.size() < 3) return false;

        unordered_map<int, Node> mp;
        
        for (int value : nums) {
            auto it = mp.find(value);
            if (it == mp.end()) {
                ++mp[value + 1].cnt[1];
            } else {
                int pos = it->second.findMin();
                --it->second.cnt[pos];
                if (it->second.empty()) {
                    mp.erase(it);
                }
                ++mp[value + 1].cnt[min(4, pos + 1)];
            }
        }

        for (const auto& p : mp) {
            auto& node = p.second;
            if (node.findMin() < 3) return false;
        }

        return true;
    }
};
