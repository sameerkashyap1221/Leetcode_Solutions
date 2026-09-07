class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int, int>> athletes;
        for (int i = 0; i < n; i++) {
            athletes.push_back({score[i], i});
        }
        sort(athletes.begin(), athletes.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.first > b.first;
             });

        vector<string> answer(n);
        for (int i = 0; i < n; i++) {
            int originalIndex = athletes[i].second;

            if (i == 0) {
                answer[originalIndex] = "Gold Medal";
            } else if (i == 1) {
                answer[originalIndex] = "Silver Medal";
            } else if (i == 2) {
                answer[originalIndex] = "Bronze Medal";
            } else {
                answer[originalIndex] = to_string(i + 1);
            }
        }
        return answer;
    }
};