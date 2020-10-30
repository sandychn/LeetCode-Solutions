class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool res1 = solve1(rec1, rec2);
        bool res2 = solve2(rec1, rec2);
        assert(res1 == res2);
        return res1;
    }

    bool solve1(vector<int>& rec1, vector<int>& rec2) {
        int minX = max(rec1[0], rec2[0]);
        int minY = max(rec1[1], rec2[1]);
        int maxX = min(rec1[2], rec2[2]);
        int maxY = min(rec1[3], rec2[3]);
        // 交集矩形为 { (minX, minY), (maxX, maxY) }

        return minX < maxX && minY < maxY;
    }

    bool solve2(vector<int>& rec1, vector<int>& rec2) {
        if (rec1[0] == rec1[2] || rec1[1] == rec1[3]) return false;
        if (rec2[0] == rec2[2] || rec2[1] == rec2[3]) return false;
        return !(rec1[2] <= rec2[0] || rec2[2] <= rec1[0] || rec1[3] <= rec2[1] || rec2[3] <= rec1[1]);
    }
};
