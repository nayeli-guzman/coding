#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using umii = unordered_map<int, int>;
using usi = unordered_set<int>;
using qi = queue<int>;
using si = stack<int>;
using spii = stack<pii>;
using qpii = queue<pii>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vc = vector<char>;
using vvc = vector<vc>;

vvi dp;
bool debug = false;

void binary_lifting(int n, vi parent, int& log) 
{   
    log = 1;

    while ((1 << log) <= n) log++;
    
    dp.assign(n+1, vi(log, 0)); // dp[u][j]: el 2^j th antecesor del nodo u

    for (int u = 1; u <= n; ++u) dp[u][0] = parent[u];

    for (int j = 1; j < log; ++j) 
    {
        for (int u = 1; u <= n; ++u) 
        {
            int mid = dp[u][j-1];
            dp[u][j] = mid ? dp[mid][j-1] : 0;
        }
    }

}

int lca(int a, int b, const int& log, const vi& lvl)
{
    if(debug) cout << "lca(" << a << ", " << b << "): ";
    
    if (lvl[a] < lvl[b]) std::swap(a,b);
    
    int diff = lvl[a] - lvl[b];

    for (int i=0; i<log; i++)
        if ((1 << i) & diff) a = dp[a][i];

    if(a == b) return b;

    for (int j = log - 1; j >= 0; --j) {
        int ua = dp[a][j], ub = dp[b][j];
        if (ua != ub) { a = ua; b = ub; }
    }

    if(debug) cout << dp[a][0] << endl; 

    return dp[a][0];
    
}

int dist(const int&a, const int& b, const int &log, const vi& depth) {
    return depth[a] + depth[b] - 2 * depth[lca(a, b, log, depth)];
}

template<typename T>
void print(vector<T> v) {
    for(auto e:v) cout<<e<<" "; cout<<endl;
}
template<typename T>
void print(vector<vector<T>> m) {
    for(auto v:m) print(v); cout << endl;
}

int main() {

    int n, q;
    cin >> n >> q;   

    vvi adj(n+1);

    for (int i=0; i<n-1; i++) {
        int a, b; cin>>a>>b; 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vb visited(n+1);
    vi parent (n+1);
    vi depth (n+1);
    qi queue;

    queue.push(1);
    parent[1] = 0;
    visited[1] = true;
    depth[1] = 0;

    while (!queue.empty())
    {
        int v = queue.front(); queue.pop();
        visited[v] = true;
        for (const auto & e: adj[v])
        {
            if (!visited[e]) {
                queue.push(e);
                parent[e] = v;
                depth[e] = depth[v] + 1;
            }
        }
    }

    // print(parent);
    // print(depth);
    int log=0;
    binary_lifting(n, parent, log);
    
    while (q-->0)
    {
        int a, b; cin>>a>>b;
        int c, d; cin>>c>>d;
        if(debug) cout << "analizando: " << a << ", " << b << ", " << c << ", " << d << endl;  

        // p1 a, b, c
        int x = lca(a, b, log, depth);
        int y = lca(a, c, log, depth);
        int z = lca(b, c, log, depth);

        int A = x;
        A = depth[y] > depth[A] ? y : A;
        A = depth[z] > depth[A] ? z : A;

        if(debug) cout << "maxi p1: " << A << endl;

        if (dist(c, A, log, depth) + dist(A, d, log, depth) != dist(c, d, log, depth))
        {
            cout << 0 << endl;
            continue;
        }

        // p1 a, b, d
        y = lca(a, d, log, depth);
        z = lca(b, d, log, depth);

        int B = x;
        B = depth[y] > depth[B] ? y : B;
        B = depth[z] > depth[B] ? z : B;

        if(debug) cout << "maxi p2: " << B << endl;

        if (dist(c,B, log, depth) + dist(B, d, log, depth) != dist(c, d, log, depth))
        {
            cout << 0 << endl;
            continue;
        }

        if(debug) cout << "hallando la distancia de " << A << ", " << B << endl;

        int ans = dist(A, B, log, depth) + 1;
        cout << ans << endl;


    }


    return 0;
}