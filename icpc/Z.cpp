#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include "../algorithms/disjointset.hpp"

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



template<typename T>
void print(vector<T> v) {
    for(auto e:v) cout<<e<<" "; cout<<endl;
}
template<typename T>
void print(vector<vector<T>> m) {
    for(auto v:m) print(v); cout << endl;
}

pair<vvi, vvi> all_pairs_with_parent(const vvi& g) {
    int n = (int)g.size();
    vvi dist(n, vi(n, INT32_MAX)), parent(n, vi(n, -1));

    qi q;

    for (int s = 0; s < n; ++s) {
        dist[s][s] = 0;
        parent[s][s] = s;      // raíz se apunta a sí misma
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                if (dist[s][v] == INT32_MAX) {
                    dist[s][v] = dist[s][u] + 1;
                    parent[s][v] = u;   // para reconstruir camino s->v
                    q.push(v);
                }
            }
        }
    }
    return {dist, parent};
}

vi get_path(int s, int t, const vvi& parent) {
    vi path;
    if (parent[s][t] == -1) return path;    // t inalcanzable
    
    for (int cur = t; cur != s; cur = parent[s][cur]) {
        if (cur == -1) { path.clear(); return path; } // seguridad

        path.push_back(cur);
        
    }
    path.push_back(s); 
    reverse(path.begin(), path.end());
    return path;
}

void solve() {

    int n, m;
    cin>>n>>m;

    vector<usi> vusi;
    vvi graph(n); // check si cambia de vvi a vusi

    for(int i=0; i<n; i++) // i -> idx de la pelicula actual
    {
        int c;
        cin>>c;
        usi us;
        bool conf = false;
        for(int j=0; j<c; j++)
        {
            int num; cin>>num;
            us.insert(num);

            if (i>0 && !conf)
            {
                for (int k=0; k<i; k++)
                {
                    if (vusi[k].find(num) != vusi[k].end())
                    {
                        conf = true;
                        graph[k].push_back(i);
                        graph[i].push_back(k);

                    }
                }
            }

        }
        vusi.push_back(us);

    }

    // cout << "calculando matriz de parents" << endl;
    auto [dist, parent] = all_pairs_with_parent(graph);
    // print(dist);

    int q; cin>>q;

    for (int i=0; i<q; i++)
    {
        int l, r; cin>>l>>r;

        int s, t;
        bool c1=false, c2=false;

        for (int j=0; j<n; j++)
        {
            if (vusi[j].find(l) != vusi[j].end()){
                s = j;
                c1 = true;
            }

            if (vusi[j].find(r) != vusi[j].end()){
                t = j;
                c2 = true;
            }

            if (c1 && c2) break;
            

        }



        if (dist[s][t] == INT32_MAX) {
                cout << "INF\n";           // no hay camino
            } else {
                cout << dist[s][t] << '\n';
                auto path = get_path(s, t, parent);
                for (int i = 0; i < (int)path.size(); ++i) {
                    if (i) cout << ' ';
                    cout << path[i];
                }
                cout << '\n';
            }

    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int n;
    // cin>>n;

    // while(n-->0) {
    //     solve();
    // }

    solve();

    return 0;
}

