class Solution { // Two Pointers
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        const int N = nums.size();
        
        vector<vector<int>> ans;
        int l = 0, r = N - 1;

        sort(nums.begin(), nums.end());
        while (l < r) {
            long long x = 0LL + nums[l] + nums[r]; // may overflow
            if (x > target) {
                --r;
            } else if (x < target) {
                ++l;
            } else {
                ans.push_back(vector<int>{nums[l++], nums[r--]});
            }
        }

        return ans;
    }
};

class HashTableSolution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        const int N = nums.size();

        unordered_map<int, vector<int>> value_positions;
        vector<bool> visit(N);

        for (int i = N - 1; i >= 0; i--) {
            value_positions[nums[i]].push_back(i);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < N; i++) {
            if (visit[i]) continue;
            visit[i] = true;
            long long tmp = 0LL + target - nums[i]; // may overflow
            if (tmp > INT_MAX || tmp < INT_MIN) continue;
            int x = tmp;
            auto it = value_positions.find(x);
            if (it != value_positions.end()) {
                vector<int>& positions = it->second;
                while (!positions.empty()) {
                    int pos = positions.back();
                    if (visit[pos]) {
                        positions.pop_back();
                    } else {
                        visit[pos] = true;
                        ans.push_back(vector<int>{nums[i], x});
                        break;
                    }
                }
                // the vector is empty,
                // so this hashtable node can be deleted
                // to decrease the number of hashtable nodes.
                if (positions.empty()) {
                    value_positions.erase(it);
                }
            }
        }

        return ans;
    }
};
