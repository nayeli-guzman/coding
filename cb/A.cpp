#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>

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
void solve() {

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a,b,k;
    cin>>a>>b>>k;

    ll i=0, j=1, last=0;

    while(i<k) {
        if(j%a!=0 && j%b!=0) {
            i++;
            last = j;
        }
        j++;
    }
    cout << j-1;

    return 0;
}