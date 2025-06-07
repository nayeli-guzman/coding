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
using vb = vector<bool>;
using vvb = vector<vb>;

template<typename T>
void print(vector<T> v) {
    for(auto e:v) cout<<e<<" "; cout<<endl;
}
template<typename T>
void print(vector<vector<T>> m) {
    for(auto v:m) print(v); cout << endl;
}

void print(usi s) {
    for(auto e:s) cout<<e<<" "; cout<<endl;
}

void solve() {

}

vvi bfs(vvc grid, vpii begs, int k) {

    int r = grid.size(), c=grid[0].size();
    vvi distances(r, vi(c, INT32_MAX));
    vpii neigh = {{1,0}, {0,1}, {-1, 0}, {0,-1}};

    qpii queue;
    for(auto beg:begs) {
        queue.push(beg);
        distances[beg.first][beg.second] = 0;
    }

    while(!queue.empty()) {
        auto [curr_x, curr_y] = queue.front();
        queue.pop();

        for(auto [dx, dy] : neigh) {
            int x = curr_x + dx, y = curr_y + dy;
            if(x>=0 && x<r && y>=0 && y<c) {
                if(distances[x][y]==INT32_MAX) {
                    distances[x][y] = distances[curr_x][curr_y] + 1;
                    queue.push({x,y});
                }
            }
        }

    }
    

    return distances;


}

int bfsPath(vvc grid, vvi comida, vvi agua, pii beg, pii end, int a, int c) {

    int r = grid.size(), col=grid[0].size();
    vvi visited(r, vi(col, INT32_MAX));
    vpii neigh = {{1,0}, {0,1}, {-1, 0}, {0,-1}};

    qpii queue; 
    queue.push(beg);
    visited[beg.first][beg.second] = 0;

    while(!queue.empty()) {
        auto [curr_x, curr_y] = queue.front();
        queue.pop();

        if(curr_x==end.first && curr_y == end.second) {
            return visited[curr_x][curr_y];
        }

        for(auto [dx, dy] : neigh) {
            int x = curr_x + dx, y = curr_y + dy;
            if(x>=0 && x<r && y>=0 && y<col) {
                if(comida[x][y]<=c && agua[x][y]<=a) {
                    visited[x][y] = visited[curr_x][curr_y] + 1;
                    queue.push({x,y});
                }
            }
        }
    }

    return -1;


}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, c, a;
    cin>>m>>n; // m filas, n cols
    cin>>c>>a;

    vvc grid(m, vc(n));
    pii beg, end;
    vpii begs_a, begs_c;

    for(int i=0; i<m; i++) {
        string t;
        cin>>t;
        for(int j=0; j<n; j++) {
            grid[i][j] = t[j];
            if (t[j]=='D') {begs_a.push_back({i,j}); begs_c.push_back({i,j});}
            else if(t[j]=='C') begs_c.push_back({i,j});
            else  if(t[j]=='A') begs_a.push_back({i,j});
            else if(t[j]=='I') beg = {i,j};
            else if(t[j]=='F') end = {i,j};
        }
    }

    // se crearán 2 matrices que representen la cantidad de bloques hasta la fuente más cercana de comida y/o agua
    vvi comida = bfs(grid, begs_c, c);
    vvi agua = bfs(grid, begs_a, a);

    int res = bfsPath(grid, comida, agua,beg, end, a, c);

    if(res==-1) {
        cout << "IMPOSIBLE";
    } else {
        cout << res;
    }

    return 0;
}