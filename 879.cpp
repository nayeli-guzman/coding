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
using vvvi = vector<vvi>;
using qpii = queue<pii>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;


template<typename T>
void print(vector<T> v) {
    for(auto e:v) cout<<e<<" "; cout<<endl;
}
template<typename T>
void print(vector<vector<T>> m) {
    for(auto v:m) print(v); cout << endl;
}

int knapsack(vi group, vi profit, int N, int minP) {

    int n=group.size()+1, m=N+1, o=minP+1;
    vvvi dp(n, vvi(m, vi(o, 0))); 

    /*
    n -> cantidad de grupos en total
    m -> maxima cantidad de personas
    o -> minima ganancia requerida
    */

    for(int i=1; i<n; i++) {
        for(int j=0; j<m; j++) {
            for(int k=0; k<o; k++) {
                if(k < profit[i]) {
                    dp[i][j][k] = dp[i-1][j][k];
                } else {
                    dp[i][j][k] = dp[i-1][j][k] + 1;
                }
            }
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

    print(dp);
    
    return dp[n-1][m-1];

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vi w = {2,3,5};
    vi v = {2,3,5};
    int W = 5;

    cout << knapsack(w,v,W);

    return 0;
}