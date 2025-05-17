#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

using i = int;
using ll = long long;
using pii = pair<i, i>;
using vi = vector<i>;
using umii = unordered_map<i, i>;
using usi = unordered_set<i>;
using vvi = vector<vi>;

void print(vi v) {
    for(auto e:v)cout<<e<<" ";cout<<endl;
}
void print(usi s) {
    for(auto e:s)cout<<e<<" ";cout<<endl;
}
void print(vvi m) {
    for(auto e:m) {print(e);}cout<<endl;
}
int minPathSum(
    vector<vector<int>>& grid
) {

    i m = grid.size(), n = grid[0].size();
    vvi dp(m, vi(n, 0));
    dp[0][0] = grid[0][0];

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            unsigned int a = INT32_MAX, b=INT32_MAX;
            if(i-1>=0) {
                a = grid[i][j] + dp[i-1][j];
            }
            if(j-1>=0) {
                b = grid[i][j] + dp[i][j-1];
            }
            if(i-1>=0 || j-1>=0)
                dp[i][j] = min(a,b);
        }
    }

    return dp[m-1][n-1];

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vvi grid = {{1,2,3},{4,5,6}};

    cout << minPathSum(grid);

    return 0;
}