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



template<typename T>
void print(vector<T> v) {
    for(auto e:v) cout<<e<<" "; cout<<endl;
}
template<typename T>
void print(vector<vector<T>> m) {
    for(auto v:m) print(v); cout << endl;
}

int maxCoins(vector<int>& v) {

    vi p = {1};
    p.insert(p.end(), v.begin(), v.end());
    p.push_back(1);


    int n = p.size()-1;

    if(n==0) {return p[0];}

    vvi dp(n+1, vi(n+1, INT32_MIN));
    vvi s(n+1, vi(n+1, 0));

    for(int i=0; i<=n; i++) {
        dp[i][0] = 0;
        dp[0][i] = 0;
        dp[i][i] = 0;
    }

    int li=0, lj =1;

    for(int l=2; l<=n; l++) {
        for(int i=1; i<=(n-l+1); i++) {
            int j = i + (l-1);
            for(int k=i; k<j; k++) {
                int res = dp[i][k] + 
                        dp[k+1][j] + 
                        p[i-1] * p[k] * p[j];
                if(dp[i][j] < res) {
                     dp[i][j] = res;
                     s[i][j] = k;
                     li = i-1;
                     lj = j;
                }
            }
        }
    }

    return dp[1][n];
}

void solve() {

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vi p = {3,1,5,8};
    cout << maxCoins(p);

    return 0;
}