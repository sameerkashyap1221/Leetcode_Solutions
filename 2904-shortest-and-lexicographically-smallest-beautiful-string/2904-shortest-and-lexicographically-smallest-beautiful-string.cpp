#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> ones;

        // Store positions of all 1s
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                ones.push_back(i);
        }

        // Not enough 1s
        if (ones.size() < k)
            return "";

        string ans = "";
        int minLen = INT_MAX;

        // Consider every consecutive group of k ones
        for (int i = 0; i + k - 1 < ones.size(); i++) {
            int left = ones[i];
            int right = ones[i + k - 1];

            int len = right - left + 1;
            string candidate = s.substr(left, len);

            if (len < minLen) {
                minLen = len;
                ans = candidate;
            }
            else if (len == minLen && candidate < ans) {
                ans = candidate;
            }
        }

        return ans;
    }
};