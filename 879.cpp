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

const int MOD = 1000000007;

int siz, minProfit, n;
vi group, profit;

// backtracking
int dfs(
    int n, int p, int i
) {
    if(n<0) return 0;
    if(i>=siz) {
        if(p>=minProfit) return 1;
        return 0;
    }
    return 
        dfs(n, p, i+1) + 
        dfs(n - group[i], p + profit[i], i+1);
}

// w memoization

vvvi dp; // n x minP x #crimes

int dip(int n, int p, int i) {
    if (n < 0) return 0;
    if (i >= siz) return p >= minProfit ? 1 : 0;
    if (dp[n][p][i] != -1) return dp[n][p][i];
    dp[n][p][i] = (dip(n, p, i + 1) + 
                    dip(n - group[i], min(p+profit[i], minProfit), i+1)) % MOD; // tomar
    return dp[n][p][i];
}

void DP(int n, int p, int i) {
    for(int j=0; j<=i; j++) dp[j][0][0] = 1;

    for(int k=0; k<=n; k++) {
       for(int q=0; q<=p; q++) {
            dp[0][n][p] = 0;                
        }
    }

    dp[0][0][0] = 1;

    for(int i = 0; i < siz; ++i) {
        for(int n = 0; n <= maxPeople; ++n) {
            for(int p = 0; p <= minProfit; ++p) {
            int ways = dp[i][n][p];
            if (ways == 0) continue;

            dp[i+1][n][p] = (dp[i+1][n][p] + ways) % MOD;

            int nn = n + group[i];
            if (nn <= maxPeople) {
                int np = min(p + profit[i], minProfit);
                dp[i+1][nn][np] = (dp[i+1][nn][np] + ways) % MOD;
            }
            }
        }
    }

    if (n < 0) return 0;
    if (i >= siz) return p >= minProfit ? 1 : 0;
    if (dp[n][p][i] != -1) return dp[n][p][i];
    dp[n][p][i] = (dip(n, p, i + 1) + 
                    dip(n - group[i], min(p+profit[i], minProfit), i+1)) % MOD; // tomar
    return dp[n][p][i];
}

int profitableSchemes(int n_, int mp, vi& g, vi& p) {
    minProfit = mp;
    group = g;
    profit =  p;
    n = n_;
    siz = group.size();
    dp.resize(n+1, vvi(minProfit+1, vi(siz+1, -1))) ; // n x minP x #crimes
    return dip(n, 0, 0);      
}




/*
int knapsack(vi group, vi profit, int N, int minP) {

    int n=group.size()+1, m=N+1, o=minP+1;
    vvvi dp(n, vvi(m, vi(o, 0))); 

    
    n -> cantidad de grupos en total
    m -> maxima cantidad de personas
    o -> minima ganancia requerida
    

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
*/
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    group = {2,3,5};
    profit = {6,7,8};
    n = 10;
    minProfit = 3;



    cout << profitableSchemes(n, minProfit, group, profit);

    return 0;
}