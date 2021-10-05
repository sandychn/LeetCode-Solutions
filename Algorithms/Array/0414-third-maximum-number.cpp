class Solution {
public:
    int thirdMax(vector<int>& nums) {
        std::optional<int> first;
        std::optional<int> second;
        std::optional<int> third;

        for (int v : nums) {
            if (!first.has_value() || v >= first) {
                if (v != first) {
                    third = second;
                    second = first;
                    first = v;
                }
            } else if (!second.has_value() || v >= second) {
                if (v != second) {
                    third = second;
                    second = v;
                }
            } else if (!third.has_value() || v >= third) {
                third = v;
            }
        }

        return third.value_or(first.value());
    }
};
