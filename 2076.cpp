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
void solve() {

}

class DisjointSet {
private:
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.assign(n, 1);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    // Encuentra la raíz del conjunto que contiene x
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    // Une los conjuntos de x e y
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return; // ya están unidos

        // Union by size: el más pequeño se une al más grande
        if (size[rootX] < size[rootY]) swap(rootX, rootY);
        parent[rootY] = rootX;
        size[rootX] += size[rootY];
    }

    // ¿Están x e y en el mismo conjunto?
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};


vector<bool> friendRequests(int n, vvi& restrictions, vvi& requests) {
    DisjointSet dset(n), dset_copy(n);
    vector<bool> ans;

    for (auto request:requests) {
        int a = request[0], b = request[1];
        dset_copy.unite(a,b);
        int cont=0;
        for(auto restr:restrictions) {
            int x = restr[0], y = restr[1];
            if(!dset_copy.connected(x, y)) {
                cont++;
            } else {
                break;
            }
        }
        if(cont==restrictions.size()) {
            dset.unite(a, b);
            ans.push_back(1);
        } else {
            ans.push_back(0);
        }
        dset_copy = dset;
    }
    return ans;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 5;
    vvi restr = {{0,1},{1,2},{2,3}};
    vvi reque = {{0,4},{1,2},{3,1},{3,4}};

    print(friendRequests(n, restr, reque));

    return 0;
}