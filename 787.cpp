#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

using ll = long long;
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
using tri = tuple<int,int,int>;

const int INF = 1e9;

template<typename T>
void print(vector<T> v) {
    for(auto e:v) cout<<e<<" "; cout<<endl;
}
template<typename T>
void print(vector<vector<T>> m) {
    for(auto v:m) print(v); cout << endl;
}

int dijkstra(
    int n, 
    int k,
    int source,
    int dest, 
    const vector<vpii>& adj
) {
    
    vvi dist(n, vi(k + 2, INT_MAX));

    dist[source][0] = 0;

    priority_queue<tri, vector<tri>, greater<tri>> pq;
    pq.push({0, source, 0}); // last is #stops; distance, src, k

    while (!pq.empty()) {
        auto [d, u, stops] = pq.top(); pq.pop();

        if (u == dest) return d;
        if (stops > k) continue;
        // u -> v

        for (auto [v, w] : adj[u]) {
            int new_cost = d+w;
            if (new_cost < dist[v][stops+1]) {
                dist[v][stops+1] = new_cost;
                pq.push({new_cost, v, stops+1});
            }
        }
    }
    return -1;
}

// int findCheapestPrice(int n, vvi& flights, int src, int dst, int k) {
    
//     vector<vpii> adj(n);

//     for(int i=0; i<flights.size(); i++) {
//         int b = flights[i][0], e = flights[i][1], w = flights[i][2];
//         adj[b].push_back({e, w});
//     }

//    return dijkstra(n, k, src, dst, adj);
   
// }

int bellman_ford(
    int k,
    int n, 
    int source, 
    const vector<vpii>& adj, 
    int dst
) {
    vi dist(n, INF);
    dist[source] = 0;

    for (int i = 0; i <= k; ++i) {
        vi temp = dist;
        for (int u = 0; u < n ; ++u) {
            for(auto e : adj[u]) {
                if (dist[u] != INF && dist[u] + e.second < temp[e.first]) {
                    temp[e.first] = dist[u] + e.second;
                }
            }
        }
        dist = temp;
    }
    /*
    for (int u = 0; u < n ; ++u) {
        for(auto e : adj[u]) {
            if (dist[u] != INF && dist[u] + e.second < dist[e.first]) {
                return -1; 
            }
        }
    }
    */

    return dist[dst] == INF ? -1 : dist[dst]; 
}
int findCheapestPrice(int n, vvi& flights, int src, int dst, int k) {
    
    vector<vpii> adj(n);

    for(int i=0; i<flights.size(); i++) {
        int b = flights[i][0], e = flights[i][1], w = flights[i][2];
        adj[b].push_back({e, w});
    }

   return bellman_ford(k, n, src, adj, dst);
   
}


int main() {
    //vvi v = {{0,1,1},{0,2,5},{1,2,1},{2,3,1}};
    vvi v = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src = 0,
        dst = 3,
        k = 1,
        n = 4;
    cout << findCheapestPrice(n, v, src, dst, k);

    return 0;
}


/*
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    while(n-->0) {
        solve();
    }

    return 0;
}
    */