class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long power = 1000;
        long long commas = 1;
        while (power <= n) {
            long long nextPower = power * 1000;
            long long count;
            if (nextPower - 1 < n)
                count = nextPower - power;
            else
                count = n - power + 1;
            ans += count * commas;
            power = nextPower;
            commas++;
        }
        return ans;
    }
};