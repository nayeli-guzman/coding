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

int calculateMinimumHP(vvi& m) {
    int r = m.size(), c = m[0].size(); 
    vvi dp(r, vi(c, 0));
    
    dp[r-1][c-1] = m[r-1][c-1]>=0 ? 1: abs(m[r-1][c-1])+1;

    for(int i=r-1; i>=0; i--) {
        for(int j=c-1; j>=0; j--) {
            if(i==r-1&&j==c-1) continue;
            int a = i+1>=r ? INT32_MAX : dp[i+1][j];
            int b = j+1>=c ? INT32_MAX : dp[i][j+1];
            if(m[i][j]>=min(a,b)) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = -m[i][j] + min(a, b);
            }
            
        }
    }

    print(dp);

    return dp[0][0];
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vvi m = {{0,0,0},{1,1,-1}};

    cout <<calculateMinimumHP(m);


    return 0;
}
