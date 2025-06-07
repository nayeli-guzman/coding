#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using umii = unordered_map<int, int>;
using usi = unordered_set<int>;
using vvi = vector<vi>;

int knapsack(vi weights, vi values, int W) {

    int n=weights.size()+1, m=W+1;
    vvi dp(n, vi(m, 0));

    for(int i=1; i<n; i++) {
        for(int j=0; j<m; j++) {
            if (j<weights[i-1]) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(
                    dp[i-1][j], 
                    dp[i-1][j - weights[i-1]] + values[i-1]
                );
            }
        }
    }
    
    return dp[n-1][m-1];

}

void selection_sort(vi &v) {
    int n=v.size();
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(v[i]>v[j]) {
                swap(v[i], v[j]);
            }
        }
    }
}

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