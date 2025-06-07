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


void print(vi v) {
    for(auto e:v) cout<<e<<" "; cout<<endl;
}

void print(usi s) {
    for(auto e:s) cout<<e<<" "; cout<<endl;
}

void print(vvi m) {
    for(auto v:m) print(v); cout << endl;
}

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

int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vi v = {1,2,5,6};
    vi w = {2,3,4,5};

    int W = 8;
    knapsack(w, v, W);

    return 0;
}