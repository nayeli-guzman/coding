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

void solve() {

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    while(n-->0) {
        solve();
    }

    return 0;
}