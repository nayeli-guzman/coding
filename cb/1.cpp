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



void print(vi v) {
    for(auto e:v) cout<<e<<" "; cout<<endl;
}

void print(usi s) {
    for(auto e:s) cout<<e<<" "; cout<<endl;
}

void solve(int x, int y, int z, int t) {
    int q=floor(x/t);
    ll r = q*z;
    cout << r;

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y, z, t; // x: dura el ex, y:cant preg, z: marks, t:solve1quest
    cin>>x>>y>>z>>t;

    solve(x,y,z,t);

    return 0;
}