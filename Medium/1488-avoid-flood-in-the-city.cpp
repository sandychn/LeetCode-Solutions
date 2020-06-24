class Solution {
public:
    vector<int> getNext(vector<int>& rains) {
        const int N = rains.size();
        unordered_map<int, int> prePos;
        vector<int> nextPos(N, -1);
        for (int i = 0; i < N; i++) {
            int rain = rains[i];
            if (prePos.count(rain)) {
                nextPos[prePos[rain]] = i;
            }
            prePos[rain] = i;
        }
        return nextPos;
    }
    
    vector<int> avoidFlood(vector<int>& rains) {
        const int N = rains.size();
        
        unordered_set<int> fullLakes;
        vector<int> nextPos(getNext(rains));
        
        using PII = pair<int, int>;
        priority_queue<PII, vector<PII>, greater<PII>> heap; // next_i, pos
        
        vector<int> res;
        for (int i = 0; i < N; i++) {
            int rain = rains[i];
            if (rain == 0) {
                if (heap.empty()) {
                    res.push_back(1); // choose any lake to dry
                } else {
                    int dry = heap.top().second;
                    heap.pop();
                    fullLakes.erase(dry);
                    res.push_back(dry);
                }
            } else {
                if (fullLakes.count(rain)) return vector<int>{}; // lake flooded
                fullLakes.insert(rain);
                if (nextPos[i] != -1) {
                    heap.emplace(nextPos[i], rain);
                }
                res.push_back(-1);
            }
        }
        return res;
    }
};
