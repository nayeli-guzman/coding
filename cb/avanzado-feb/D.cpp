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
using vusi = vector<usi>;



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

    int n, m, x;
    cin>>n>>m;
    vusi master(n+1); // master[i] -> las especies que dependen de i
    vi count(n+1, 0); // count[i] -> cant de especies de las que depende i

    while(m-->0) {
        int e, d;
        cin>>e>>d;
        master[d].insert(e);
        count[e]++;
    }

    cin>>x;

    qi queue;
    usi set;
    queue.push(x);
    int res =0;
    count[x]--;

    while (!queue.empty()) {

        int curr = queue.front();
        queue.pop();
        set.insert(curr);

        if(count[curr]>0) {
            continue;
        }

        for(auto dep:master[curr]) {
            count[dep]--;
            queue.push(dep);
            
        }
        res++;
    }
    
    if(res==0) cout << res;
    else cout << res-1;
    

    return 0;
}