class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        return aux(numerator, denominator);
    }

    std::string aux(std::int64_t numerator, std::int64_t denominator) {
        std::string ret;
        if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) {
            ret += "-";
        }
        numerator = std::abs(numerator);  // std::abs(INT_MIN) may cause `int` overflow; use std::int64_t
        denominator = std::abs(denominator);  // std::abs(INT_MIN) may cause `int` overflow; use std::int64_t
        ret += std::to_string(numerator / denominator);
        numerator %= denominator;
        if (numerator == 0) {
            return ret;
        }
        ret += ".";
        std::unordered_map<std::int64_t, int> visited;
        while (numerator != 0) {
            numerator *= 10;
            auto v = numerator / denominator;
            if (!visited.emplace(numerator, static_cast<int>(ret.size())).second) {
                int index = visited[numerator];
                ret.insert(ret.begin() + index, '(');
                ret += ')';
                break;
            }
            numerator %= denominator;
            ret += std::to_string(v);
        }
        return ret;
    }
};
