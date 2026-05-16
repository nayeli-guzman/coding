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
void solve() {

}

bool cycle = false;

void dfs(int node, 
    const vvi& adj, 
    string colors, 
    vvi& dp, 
    vb &visited,
    vb &stk
) {
    if(stk[node]) {
        cycle = true;
        return;
    }

    if (visited[node]) return;

    visited[node] = true;
    stk[node] = true;

    int color = colors[node]-'a';

    for (int v : adj[node]) {
        dfs(v, adj, colors, dp, visited, stk);
        if(cycle) return;

        for(int i=0; i<27; i++) {
            dp[node][i] = max(dp[node][i], dp[v][i]);
        }        
    }

    dp[node][color] += 1;
    stk[node] = false;

}


int largestPathValue(string colors, vvi& edges) {
    int n = colors.size();
    vvi adj(n);
    vvi dp(n, vi(27, 0)); // columnas serán los colores
    vb visited(n, false);   
    vb stk(n, false);   
    for(auto edge:edges) {
        int a = edge[0], b = edge[1];
        adj[a].push_back(b);
    }
    
    for(int i=0; i<n; i++) {
        if (!visited[i]) {
            dfs(i, adj, colors, dp, visited, stk);
            if (cycle) return -1;
        }
    }
    int ans = INT32_MIN;
    for(auto vec:dp) {
        for(auto ele:vec) {
            ans = max(ans, ele);
        }
    }

    return ans;
}



int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string colors = "abaca";
    vvi edges = {{0,1},{0,2},{2,3},{3,4}};
    cout << largestPathValue(colors, edges);

    return 0;
}