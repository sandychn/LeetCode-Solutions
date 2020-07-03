class Solution {
public:
    static int square(int x) {
        return x * x;
    }

    int numberOfBoomerangs(vector<vector<int>>& points) {
        const int N = points.size();
        
        int res = 0;

        int dis[N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dis[j] = square(points[i][0] - points[j][0])
                    + square(points[i][1] - points[j][1]);
            }
            sort(dis, dis + N);
            int equ = 0;
            for (int j = 0; j < N; j++) {
                if (j > 0 && dis[j - 1] == dis[j]) {
                    ++equ;
                } else {
                    res += equ * (equ - 1);
                    equ = 1;
                }
            }
            if (equ) {
                res += equ * (equ - 1);
            }
        }

        return res;
    }
};

class MySolution {
public:
    static int square(int x) {
        return x * x;
    }

    int numberOfBoomerangs(vector<vector<int>>& points) {
        const int N = points.size();
        
        int res = 0;

        for (int i = 0; i < N; i++) {
            unordered_map<int, int> distance_count;
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                int dis = square(points[i][0] - points[j][0])
                    + square(points[i][1] - points[j][1]);
                ++distance_count[dis];
            }
            for (int k = 0; k < N; k++) {
                if (i == k) continue;
                int dis = square(points[i][0] - points[k][0])
                    + square(points[i][1] - points[k][1]);
                res += distance_count[dis] - 1;
            }
        }

        return res;
    }
};
