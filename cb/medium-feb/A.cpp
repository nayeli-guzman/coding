#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using pii = pair<int, int>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vpii = vector<pii>;

vvi bfs(const vvc& grid, const vpii& starts, int n, int m) {
    vpii dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    vvi dist(n, vector<int>(m, INT32_MAX));
    queue<pii> q;

    for (auto beg : starts) {
        dist[beg.first][beg.second] = 0;
        q.push(beg);
    }

    while (!q.empty()) {
        pii curr = q.front();
        q.pop();
        int i = curr.first, j = curr.second;

        for (auto [dx, dy] : dir) {
            int x = i + dx, y = j + dy;
            if (x >= 0 && x < n && y >= 0 && y < m) {
                if (dist[x][y] == INT32_MAX) {
                    dist[x][y] = dist[i][j] + 1;
                    q.push({x, y});
                }
            }
        }
    }

    return dist;
}

int bfsCamino(const vvc& grid, pii start, pii end, const vvi& distComida, const vvi& distAgua, int c, int a) {
    int n = grid.size(), m = grid[0].size();
    vvi dist(n, vector<int>(m, INT32_MAX));
    queue<pii> q;
    dist[start.first][start.second] = 0;
    q.push(start);
    vpii dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == end.first && y == end.second) return dist[x][y];

        for (auto [dx, dy] : dir) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (distComida[nx][ny] <= c && distAgua[nx][ny] <= a) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, c, a;
    cin >> n >> m >> c >> a;
    vvc grid(n, vector<char>(m));
    vpii beg_c, beg_a;
    pii beg, end;

    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        for (int j = 0; j < m; j++) {
            grid[i][j] = t[j];
            if (t[j] == 'I') beg = {i, j};
            else if (t[j] == 'F') end = {i, j};
            if (t[j] == 'C' || t[j] == 'D') beg_c.push_back({i, j});
            if (t[j] == 'A' || t[j] == 'D') beg_a.push_back({i, j});
        }
    }

    vvi comida = bfs(grid, beg_c, n, m);
    vvi agua = bfs(grid, beg_a, n, m);

    int res = bfsCamino(grid, beg, end, comida, agua, c, a);

    if (res == -1) cout << "IMPOSIBLE\n";
    else cout << res << "\n";

    return 0;
}
