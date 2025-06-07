#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <stack>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using umii = unordered_map<int, int>;
using usi = unordered_set<int>;
using qi = stack<int>;
using si = stack<int>;
using spii = stack<pii>;
using qpii = stack<pii>;
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
template<typename T, typename Q>
void print(vector<pair<T,Q>> v) {
    for(auto [x,y]:v) cout<<x<<" "<<y<<endl; cout<<endl;
}

int dfs(const vvi &grid, const pii &beg, vvi& dp, int n, int m) {

    vpii dir = {{-1, 0},{0,-1},{0,1},{1,0}};
    int res = 1;
    
    auto [i,j] = beg;
    if(dp[i][j]!=INT32_MIN) return dp[i][j];

    for(auto [dx, dy]:dir) {
        int x = i+dx, y=j+dy;
        if(x>=0 && x<n && y>=0 && y<m && grid[i][j]<grid[x][y]) {
            res = max(res, 1 + dfs(grid, {x,y}, dp, n, m));
        }
    }

    dp[i][j] = res;
    
    return res;

}

int longestIncreasingPath(vvi& m) {

    int r=m.size(), c=m[0].size();
    vvi dp(r, vi(c, INT32_MIN));
    vpii neigh = {{0,1},{1,0},{0,-1},{-1,0}};
    int maxi = INT32_MIN;

    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            dfs(m, {i,j}, dp, r, c);
            maxi = max(maxi, dp[i][j]);
        }
    }
    return maxi;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vvi m = {{1,2},{2,3}};
    cout << longestIncreasingPath(m);


    return 0;
}
    
