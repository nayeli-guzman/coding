#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vb = vector<bool>;
using umii = unordered_map<int, int>;
using usi = unordered_set<int>;
using vvi = vector<vi>;
using vvb = vector<vb>;

struct KnapRes {
    int value;
    vi items; // índices 0-based tomados
};

KnapRes knapsack_with(const vi& w, const vi& val, int W) {
    int n = (int)w.size();
    int m = W + 1;

    // dp[i][j] = máximo valor usando primeros i ítems con capacidad j
    vvi dp(n + 1, vi(m, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= W; ++j) {
            dp[i][j] = dp[i - 1][j]; // no tomar
            if (j >= w[i - 1])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i - 1]] + val[i - 1]);
        }
    }

    // rebuilt
    vi items;
    int i = n, j = W;
    while (i > 0 && j >= 0) {
        if (dp[i][j] == dp[i - 1][j]) {
            --i;
        } else {
            items.push_back(i - 1);
            j -= w[i - 1];
            --i;
        }
        if (j == 0) break;
    }
    reverse(items.begin(), items.end());
    return { dp[n][W], items };
}

struct SubsetSumRes {
    bool possible; // ¿existe subconjunto que sume W?
    vi items;      // índices 0-based elegidos
};

SubsetSumRes subset_sum(const vi& values, int W) {
    int n = (int)values.size();
    int m = W + 1;

    // dp[i][j]: ¿puedo formar suma j con los primeros i elementos?
    vvb dp(n + 1, vb(m, false));
    dp[0][0] = true;

    for (int i = 1; i <= n; ++i) {
        int v = values[i - 1];
        for (int j = 0; j <= W; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= v && dp[i - 1][j - v]) dp[i][j] = true;
        }
    }

    if (!dp[n][W]) return {false, {}};

    // rebuilt
    vi items;
    int i = n, j = W;
    while (i > 0 && j >= 0) {
        int v = values[i - 1];
        if (j >= v && dp[i - 1][j - v]) { // tomar i-1
            items.push_back(i - 1);
            j -= v;
        }
        --i; // subir fila
        if (j == 0) break;
    }
    reverse(items.begin(), items.end());
    return {true, items};
}

struct LISRes {
    int len;  // longitud de la LIS
    vi idx;   // índices 0-based en la LIS
};

LISRes LIS(const vi& a, bool strictly = true) {
    int n = (int)a.size();
    if (n == 0) return {0, {}};

    vi dp(n, 1), prev(n, -1);
    int bestLen = 1, bestEnd = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            bool ok = strictly ? (a[j] < a[i]) : (a[j] <= a[i]);
            if (ok && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > bestLen) {
            bestLen = dp[i];
            bestEnd = i;
        }
    }

    // rebuilt
    vi pathIdx;
    for (int k = bestEnd; k != -1; k = prev[k]) pathIdx.push_back(k);
    reverse(pathIdx.begin(), pathIdx.end());
    return {bestLen, pathIdx};
}

void matrix_chain_multiplication(int n, vi p) {

    vvi dp(n+1, vi(n+1, INT32_MAX));
    vvi s(n+1, vi(n+1, 0));

    for(int i=0; i<=n; i++) {
        dp[i][0] = 0;
        dp[0][i] = 0;
        dp[i][i] = 0;
    }

    for(int l=2; l<=n; l++) {
        for(int i=1; i<=(n-l+1); i++) {
            int j = i + (l-1);
            for(int k=i; k<j; k++) {
                int res = dp[i][k] + 
                        dp[k+1][j] + 
                        p[i-1] * p[k] * p[j];
                if(dp[i][j] > res) {
                     dp[i][j] = res;
                     s[i][j] = k;
                }
            }
        }
    }

}


struct LCSRes {
    int len;     // longitud de la LCS
    vi idx_s;    // índices 0-based elegidos en s
    vi idx_t;    // índices 0-based elegidos en t
    string lcs;  // la subsecuencia común
};

LCSRes LCS(const string& s, const string& t) {
    int n = (int)s.size(), m = (int)t.size();
    vvi dp(n + 1, vi(m + 1, 0));

    // dp[i][j] = longitud de la LCS entre los prefijos s[0..i-1] y t[0..j-1].
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // rebuilt from (n,m)
    string lcs;
    vi idxS, idxT;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            lcs.push_back(s[i - 1]);
            idxS.push_back(i - 1);
            idxT.push_back(j - 1);
            --i; --j;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
    reverse(lcs.begin(), lcs.end());
    reverse(idxS.begin(), idxS.end());
    reverse(idxT.begin(), idxT.end());

    return {(int)lcs.size(), idxS, idxT, lcs};
}


struct BinaryLifting {
    int n, LOG;
    vvi up;      // up[k][v] = ancestro 2^k de v, -1 si no hay
    vi depth;
    vvi g;

    BinaryLifting(int n): n(n), g(n) {
        LOG = 1;
        while ((1 << LOG) <= n) ++LOG;
        up.assign(LOG, vi(n, -1));
        depth.assign(n, 0);
    }

    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    void dfs(int u, int p) {
        up[0][u] = p;
        for (int k = 1; k < LOG; ++k) {
            int mid = up[k-1][u];
            up[k][u] = (mid == -1 ? -1 : up[k-1][mid]);
        }
        for (int v : g[u]) if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }

    void build(int root = 0) {
        dfs(root, -1);
    }

    // sube x en t niveles; retorna -1 si no existe
    int kth_ancestor(int x, int t) const {
        for (int k = 0; k < LOG && x != -1; ++k) {
            if (t & (1 << k)) x = up[k][x];
        }
        return x;
    }

    int lca(int a, int b) const {
        if (depth[a] < depth[b]) swap(a, b);
        // eleva a al nivel de b
        int diff = depth[a] - depth[b];
        a = kth_ancestor(a, diff);
        if (a == b) return a;
        // salta en potencias; el primer punto donde difieren los padres
        for (int k = LOG - 1; k >= 0; --k) {
            if (up[k][a] != up[k][b]) {
                a = up[k][a];
                b = up[k][b];
            }
        }
        // ahora su padre es el LCA
        return up[0][a];
    }
};
