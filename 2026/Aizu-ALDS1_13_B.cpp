#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <tuple>

using namespace std;

using vi = vector<int>;
using vii = vector<vi>;
using qi = queue<int>;
using pii = pair<int, int>;
using T = tuple<int, pii, vii>;

int S = 3;
vii M(S, vi(S,0));
int x, y;

bool debug=0;


string mtostring(const vii& m) {
    string ans = "";
    for (auto e : m) {
        for (auto a : e) {
            ans += char('0' + a);
        }
    }
    return ans;
}

int main() {

    vector<pii> neigs = {{1,0}, {0,1}, {-1,0}, {0, -1}};


    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cin>>M[i][j];
            if (M[i][j] == 0) {
                x=i; y=j;
            }
            if (debug) cout << M[i][j] << " ";
        } if (debug) cout << endl;
    }

    unordered_set<string> visited;

    queue<T> cola;
    int dist = 0;
    pii coord = {x,y};
    string m = mtostring(M);

    cola.push({dist, coord, M});
    visited.insert(m);

    while (!cola.empty()){
        tuple<int, pii, vii> h = cola.front();
        dist = get<0>(h); coord = get<1>(h); M = get<2>(h);
        int x = coord.first, y=coord.second;
        m = mtostring(M);

        if(debug) cout << "Anlizando dist="<<dist<<" coord(x="<<coord.first<<" y="<<coord.second<<") m="<<m<<endl;

        if (m == "123456780") {
            cout << dist<< endl; return 0;
        }
    
        cola.pop();

        for (auto neig:neigs) {
            int dx = x + neig.first, dy = y + neig.second;
            vii M_copy(M);

            if (dx >= 0 && dx < 3  && dy >= 0 && dy < 3) {
                
                M_copy[x][y] = M_copy[dx][dy];
                M_copy[dx][dy] = 0;

                string new_state = mtostring(M_copy);
                if (visited.find(new_state) != visited.end()) {
                    continue;
                }

                if (debug) cout << "av_neig: " << new_state << endl;

                cola.push(make_tuple(dist+1, pii(dx, dy), M_copy));
                visited.insert(new_state);
                
            }

        }
        if (debug) cout << endl;

        
    }
    
    cout << -1;




    return 0;
}