#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> dependientes(N + 1);

    vector<int> cont_deps(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int e_i, d_i;
        cin >> e_i >> d_i;
        dependientes[d_i].push_back(e_i);
        cont_deps[e_i]++;
    }

    int X;
    cin >> X;

    queue<int> cola;
    set<int> afectados;

    cola.push(X);
    afectados.insert(X);

    while (!cola.empty()) {
        int especie = cola.front();
        cola.pop();

        for (int dep : dependientes[especie]) {
            cont_deps[dep]--;
            if (cont_deps[dep] == 0) {
                if (afectados.find(dep) == afectados.end()) {
                    afectados.insert(dep);
                    cola.push(dep);
                }
            }
        }
    }

    cout << (int)afectados.size() - 1 << endl;

    return 0;
}
