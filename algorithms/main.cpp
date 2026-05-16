#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>

using namespace std;

using int = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
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
using vb = vector<bool>;


template<typename T>
void print(vector<T> v) {
    for(auto e:v) cout<<e<<" "; cout<<endl;
}
template<typename T>
void print(vector<vector<T>> m) {
    for(auto v:m) print(v); cout << endl;
}

template<typename T>
void print(T e) {
    cout<<e<<endl;
}

vvi dp;

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

int lca(int a, int b, int log, const vi& lvl)
{
    if (lvl[a] < lvl[b]) std::swap(a,b);
    
    int diff = lvl[a] - lvl[b];

    for (int i=0; i<log; i++)
        if ((1 << i) & diff) a = dp[a][i];

    if(a == b) return b;

    for (int j = log - 1; j >= 0; --j) {
        int ua = dp[a][j], ub = dp[b][j];
        if (ua != ub) { a = ua; b = ub; }
    }
    return dp[a][0];
    
}


void solve() {

    /*
     1. khan (aislar y etiquetar ciclos)
    */
    int n, m;
    cin>>n;
    vi next(n+1,0);

    for(int i=1; i<=n; i++)
        cin>>next[i];
    
    vi in_deg(n+1, 0);
    for(int i=1; i<=n; i++)
        in_deg[next[i]]++;

    qi cola;

    for(int i=1; i<=n; i++)
        if(in_deg[i] == 0)
            cola.push(i);
    
    while(!cola.empty())
    {
        int top = cola.front(); cola.pop();
        // curr -> u
        int u = next[top];
        if (--in_deg[u] == 0) cola.push(u);    
    }

    vb in_cycle(n+1, false);
    for(int i=1; i<=n; i++) in_cycle[i] = in_deg[i]>0 ? true:false;

    vi cycle_id(n+1, -1), pos(n+1, -1), len_cycle(n+1,-1), dist(n+1, 0), entry(n+1, -1);

    int IDX=0;

    for(int u=1; u<=n; u++)
    { // u-> v
        if (cycle_id[u]== -1 && in_cycle[u]) 
        {
            vi temp_path;
            int curr = u;
            do
            {
                temp_path.emplace_back(curr);
                curr = next[curr];
            } while (curr != u);

            for(int i=0; i<temp_path.size(); i++)
            {
                cycle_id[temp_path[i]] = IDX;
                pos[temp_path[i]] = i;
            }          
            len_cycle[IDX++] = temp_path.size();
        }
    }

    vvi rev(n+1);
    for(int u=1; u<=n; u++) rev[next[u]].emplace_back(u);
    
    qi cola_2;

    for(int u=1; u<=n; u++) 
        if (in_cycle[u]) 
        {
            cola_2.push(u);
            dist[u] = 0;
            entry[u] = u;
        }

    while (!cola_2.empty())
    {
        int v = cola_2.front(); cola_2.pop();
        for(auto u : rev[v])
        {
            if (cycle_id[u] == -1)
            {
                cycle_id[u] = cycle_id[v];
                dist[u] = dist[v] + 1;
                entry[u] = entry[v];
                cola_2.push(u);
            }
        }
    }
    
    vi parent(n+1, 0);
    for (int u = 1; u <= n; ++u) parent[u] = in_cycle[u] ? 0 : next[u];
    
    int log=0;
    binary_lifting(n, parent, log);

    // casos
    
    cin>>m;

    while(m-->0) 
    {
        int a, b;
        cin >> a >> b;

        if(cycle_id[a] != cycle_id[b]) cout << -1;
        else if (a == b) cout << 0;
        else if (entry[a] == entry[b])
        {
            int ans = dist[a] + dist[b] - 2 *  dist[lca(a, b, log, dist)];
            cout << ans;
        } else if (entry[a] != entry[b])
        {
            int L = len_cycle[cycle_id[a]];
            int diff = abs( pos[entry[a]] - pos[entry[b]]);
            int ans = min( diff, L - diff );
            cout << ans + dist[a] + dist[b];
        }
    }

    
    
}


int main() {

    solve();

    // int n = 9;
    // vi parent(n, -1);
    // parent[0] = -1;
    // parent[1] = 0;  parent[2] = 0;
    // parent[3] = 1;  parent[4] = 1;
    // parent[5] = 2;  parent[6] = 2;
    // parent[7] = 6;  parent[8] = 6;

    // vvi dp;
    // int LOG = 0;
    // binary_lifting(n, parent, dp, LOG);
    // vi lvl = compute_levels(n, parent);

    // vector<pair<int,int>> tests = {
    //     {3,4}, // esperado: 1
    //     {3,5}, // esperado: 0
    //     {7,8}, // esperado: 6
    //     {7,4}, // esperado: 0
    //     {1,4}, // esperado: 1
    //     {0,8}, // esperado: 0
    //     {6,6}, // esperado: 6
    // };

    // for (auto [a,b] : tests) {
    //     cout << "lca(" << a << ", " << b << ") = " << lca(a,b,dp,LOG,lvl) << "\n";
    // }
    return 0;
}
