#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <limits>
#include <stack>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using umii = unordered_map<int, int>;
using usi = unordered_set<int>;
using vvi = vector<vi>;
using vpii = vector<pii>;
using vb = vector<bool>;
using vvb = vector<vb>;
using qpii = queue<pii>;
using spii = stack<pii>;

const int INF = numeric_limits<int>::max();

struct Edge {
    int u, v, w;
};

void bfs(vvi grid, pii beg, pii end, int n, int m) {

    vpii dir = {{-1, 0},{0,-1},{0,1},{1,0}};

    vvb visited(n, vb(m,false));
    qpii queue;

    queue.push(beg);
    visited[beg.first][beg.second] = true;

    while (!queue.empty()) {
        pii curr = queue.front();
        queue.pop();
        int i = curr.first, j=curr.second;
        for(auto [dx, dy]:dir) {
            int x =i+dx, y=j+dy;
            if(x>=0 && x<n && y>=0 && y<m && visited[x][y]==false) {
                visited[x][y] = true;
                queue.push({x,y});
            }
        }
    }
}

void dfs_aux(vvi& grid, int i, int j, int n, int m, vvb& visited) {

    if (i < 0 || i >= n || j < 0 || j >= m) return;
    if (visited[i][j]) return;

    visited[i][j] = true;

    vpii dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    for (auto [dx, dy] : dir) {
        int x = i + dx, y = j + dy;
        dfs(grid, x, y, n, m, visited);
    }
}

void dfs_recursive(vvi grid, pii beg, int n, int m) {
    vvb visited(n, vb(m, false));
    dfs_aux(grid, beg.first, beg.second, n, m, visited);
}

void dfs_iterative(vvi& grid, pii beg, int n, int m) {
    vpii dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    vvb visited(n, vb(m, false));
    stack<pii> stk;

    stk.push(beg);
    visited[beg.first][beg.second] = true;

    while (!stk.empty()) {
        pii curr = stk.top();
        stk.pop();
        int i = curr.first, j = curr.second;

        //cout << "Visitando: (" << i << ", " << j << ")\n";

        for (auto [dx, dy] : dir) {
            int x = i + dx, y = j + dy;
            if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y]) {
                visited[x][y] = true;
                stk.push({x, y});
            }
        }
    }
}

bool bellman_ford(int n, int source, const vector<Edge>& edges, vi& dist) {
    dist.assign(n, INF);
    dist[source] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (const Edge& e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    // Comprobamos ciclo negativo
    for (const Edge& e : edges) {
        if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
            return false; 
        }
    }

    return true; 
}

bool floyd_warshall(int n, const vector<Edge>& edges, vvl& dist, vvi* nxt = nullptr) {

    dist.assign(n, vector<ll>(n, INF));
    for (int i = 0; i < n; ++i) dist[i][i] = 0;

    for (const auto& e : edges) {
        dist[e.u][e.v] = min(dist[e.u][e.v], e.w);
    }

    if (nxt) {
        nxt->assign(n, vi(n, -1));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (dist[i][j] < INF) (*nxt)[i][j] = j;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) if (dist[i][k] < INF) {
            for (int j = 0; j < n; ++j) if (dist[k][j] < INF) {
                ll nd = dist[i][k] + dist[k][j];
                if (nd < dist[i][j]) {
                    dist[i][j] = nd;
                    if (nxt) (*nxt)[i][j] = (*nxt)[i][k];
                }
            }
        }
    }

    // Comprobamos ciclo negativo: algún dist[i][i] < 0
    for (int i = 0; i < n; ++i) {
        if (dist[i][i] < 0) return false;
    }
    return true;
}

int main() {


    

    return 0;
}
