#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using vi = vector<int>;
using vii = vector<vi>;
using pii = pair<int, int>;

int S = 4;
vii M(S, vi(S, 0));
vi orig = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};

int x, y;
int limit = 0;
int answer = -1;

const int INF = INT32_MAX;

vector<pii> neigs = {
    {1, 0},   // 0 down
    {0, 1},   // 1 right
    {-1, 0},  // 2 up
    {0, -1}   // 3 left
};

int opposite[4] = {2, 3, 0, 1};

bool debug = 0;

int dist_tile(int n, int i, int j) {
    if (n == 0) return 0;
    int a=(n-1)/S, b=(n-1)%S;
    return abs(i-a) + abs(j-b);
}

int manhattan(const vii& m) {
    int ans = 0;

    for (int i = 0; i < S; i++) {
        for (int j = 0; j < S; j++) {
            ans += dist_tile(m[i][j], i, j);
        }
    }

    return ans;
}

int dfs_aux(vii& grid, int i, int j, int dist, int man, int prev) {
    int f = dist + man;

    if (f > limit) return f;

    if (man == 0) {
        answer = dist;
        return -1;
    }

    int next_limit = INT32_MAX;

    for (int k = 0; k < 4; k++) {
        if (prev != -1 && k == opposite[prev]) { // para no pasar por la misma casilla (la q acaba de llamar)
            continue;
        }

        int dx=i+neigs[k].first, dy=j+neigs[k].second;

        if (dx<0 || dx>=S || dy<0 || dy>=S) continue;

        int moved = grid[dx][dy];

        int old_dist = dist_tile(moved, dx, dy);
        int new_dist = dist_tile(moved, i, j);

        int new_man = man - old_dist + new_dist;

        swap(grid[i][j], grid[dx][dy]);

        int res = dfs_aux(grid, dx, dy, dist + 1, new_man, k);

        swap(grid[i][j], grid[dx][dy]);

        if (res == -1) return -1;

        next_limit = min(next_limit, res);
    }

    return next_limit;
}

void dfs_recursive(vii& grid, pii beg) {
    int man = manhattan(grid);
    limit = man;

    while (true) {
        int res = dfs_aux(grid, beg.first, beg.second, 0, man, -1);

        if (res == -1) {
            return;
        }

        limit = res;
    }
}

int main() {
    for (int i = 0; i < S; i++) {
        for (int j = 0; j < S; j++) {
            cin >> M[i][j];

            if (M[i][j] == 0) {
                x = i;
                y = j;
            }
        }
    }

    pii coord = {x, y};

    dfs_recursive(M, coord);

    cout << answer << endl;

    return 0;
}