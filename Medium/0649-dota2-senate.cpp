class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant;
        queue<int> dire;
        
        int n = senate.size();

        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }

        while (!radiant.empty() && !dire.empty()) {
            int x = radiant.front();
            int y = dire.front();
            radiant.pop();
            dire.pop();
            if (x < y) {
                radiant.push(x + n);
            } else {
                dire.push(y + n);
            }
        }

        return radiant.empty() ? "Dire" : "Radiant";
    }
};
