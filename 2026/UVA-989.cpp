#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;
using vii = vector<vi>;
using vb = vector<bool>;
using vbb = vector<vb>;

bool debug = 0;

vbb rows, cols, boxs;
vii s;
int n;

bool back(const int &pos) {

    if (pos==n*n*n*n) return true;

    int i=pos/(n*n), j=pos%(n*n);

    if (s[i][j]) return back(pos+1);
    
    int b = (i / n) * n + (j / n);

    if(debug) cout << "analizando i=" << i << " j=" <<j << " b=" << b << endl;

    for (int k=1; k<=n*n; k++) {
        if (!rows[i][k] and !cols[j][k] and !boxs[b][k]) {
            rows[i][k] = 1;
            cols[j][k] = 1;
            boxs[b][k] = 1;
            s[i][j] = k;
            
            if (back(pos+1)) return 1;

            rows[i][k] = 0;
            cols[j][k] = 0;
            boxs[b][k] = 0;
            s[i][j] = 0;
            
        }
    }
    return 0;
}




int main() {

    bool first = 1;

    while (cin >> n) {
        if (!first) cout << endl;
        first = 0;

        s.assign(n*n, vi(n*n,0));
        rows.assign(n*n, vb(n*n+1, 0));
        cols.assign(n*n, vb(n*n+1, 0));
        boxs.assign(n*n, vb(n*n+1, 0));  // 0 1 2
                                        // 3 4 5
                                        // 6 7 8
                                        // (r / n) * n + (c / n)
        bool inv = 0;

        for (int i=0; i<n*n; i++) {
            for (int j=0; j<n*n; j++) {
                cin>>s[i][j];
                
                int x = s[i][j];
                int bi = (i / n) * n + (j / n);

                if (x != 0) {
                    if (rows[i][x] || cols[j][x] || boxs[bi][x]) {
                        inv = 1;
                    } else {
                        rows[i][x] = 1;
                        cols[j][x] = 1;
                        boxs[bi][x] = 1;
                    }
                }
            }
        }

        // for (auto e:s) {
        //     for (auto i:e) {
        //         cout << i << " ";
        //     } cout << endl;
        // }
        // cout << endl;

        if (inv) {
            cout << "NO SOLUTION" << endl;
            continue;
        }

        if (!back(0)) {
            cout << "NO SOLUTION" << endl;
            continue;
        }

        for (int i = 0; i < n*n; i++) {
            for (int j = 0; j < n*n; j++) {
                if (j) cout << " ";
                cout << s[i][j];
            }
            cout << endl;
        }

    }
    

    return 0;
}