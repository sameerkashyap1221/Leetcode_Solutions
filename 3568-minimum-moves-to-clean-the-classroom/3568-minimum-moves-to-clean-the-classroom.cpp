class Solution {
public:
    int minMoves(vector<string>& g, int E) {
        int m = g.size(), n = g[0].size(), sr, sc, L = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (g[i][j] == 'S') sr = i, sc = j;
                if (g[i][j] == 'L') id[i][j] = L++;
            }

        int all = (1 << L) - 1;

        // Maximum energy reached for each state
        vector<vector<vector<int>>> best(
            m, vector<vector<int>>(n, vector<int>(1 << L, -1))
        );

        queue<array<int, 4>> q;
        q.push({sr, sc, 0, E});
        best[sr][sc][0] = E;

        int d = 0;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, mask, e] = q.front();
                q.pop();

                if (mask == all) return d;
                if (e == 0) continue;

                for (int k = 0; k < 4; k++) {
                    int x = r + dx[k], y = c + dy[k];

                    if (x < 0 || x >= m || y < 0 || y >= n ||
                        g[x][y] == 'X')
                        continue;

                    int ne = e - 1;
                    int nm = mask;

                    if (g[x][y] == 'L')
                        nm |= (1 << id[x][y]);

                    if (g[x][y] == 'R')
                        ne = E;

                    if (ne > best[x][y][nm]) {
                        best[x][y][nm] = ne;
                        q.push({x, y, nm, ne});
                    }
                }
            }

            d++;
        }

        return -1;
    }
};