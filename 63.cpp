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
int uniquePathsWithObstacles(
    vector<vector<int>>& grid
) {

    if(grid[0][0] == 1) return 0;
    i m = grid.size(), n = grid[0].size();
    if(n==1 && m==1) return 1;
    vvi dp(m, vi(n, 0));

    if(n>1) dp[0][1] = grid[0][1] == 1 ? 0:1;
    if(m>1)dp[1][0] = grid[1][0] == 1 ? 0:1;


    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(i-1>=0 && grid[i][j] != 1) {
                dp[i][j] = dp[i][j] + dp[i-1][j];
            }
            if(j-1>=0 && grid[i][j] != 1) {
                dp[i][j] = dp[i][j] + dp[i][j-1];
            }
        }
    }

    return dp[m-1][n-1];

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vvi grid = {{0}};

    cout << uniquePathsWithObstacles(grid);

    return 0;
}