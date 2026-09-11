class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count = 0;

        for (int num = 100; num <= 998; num += 2) {
            int x = num;
            int need[10] = {};
            need[x % 10]++;
            x /= 10;
            need[x % 10]++;
            x /= 10;
            need[x % 10]++;
            int have[10] = {};
            for (int d : digits) {
                have[d]++;
            }
            bool possible = true;
            for (int d = 0; d <= 9; d++) {
                if (need[d] > have[d]) {
                    possible = false;
                    break;
                }
            }
            if (possible)
                count++;
        }
        return count;
    }
};