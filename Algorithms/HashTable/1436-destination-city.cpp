class Solution {

    struct Degrees {
        int m_inDegree = 0;
        int m_outDegree = 0;
    };

public:
    string destCity(vector<vector<string>>& paths) {
        std::unordered_map<std::string, Degrees> degree;

        for (const auto& path : paths) {
            const auto& x = path[0];
            const auto& y = path[1];
            ++degree[x].m_outDegree;
            ++degree[y].m_inDegree;
        }

        for (const auto& e : degree) {
            if (e.second.m_outDegree == 0) return e.first;
        }

        throw std::invalid_argument("answer does not exist");
    }
};
