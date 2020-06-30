class Solution {
public:
    bool isPathCrossing(string path) {
        pair<int, int> pos;
        set<pair<int, int>> st;
        st.insert(pos);
        for (char ch : path) {
            switch (ch) {
                case 'N':
                    --pos.first;
                    break;
                case 'S':
                    ++pos.first;
                    break;
                case 'E':
                    ++pos.second;
                    break;
                case 'W':
                    --pos.second;
                    break;
            }
            if (st.count(pos)) return true;
            st.insert(pos);
        }
        return false;
    }
};
