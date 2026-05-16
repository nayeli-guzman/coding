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
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin>>n>>k;

    vector<vector<char>> orig(n, vector<char>(n));
    vector<vector<char>> dots(n, vector<char>(n, '.'));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>orig[i][j];
        }
    }

    vvc temp = orig;
    vvc grid(n*n, vc(n*n));
    int x=0, y=0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if (temp[i][j] == '#') {
                int prev_y = y;
                for(int k=0; k<n; k++, x++) {
                    for(int l=0, y=prev_y; l<n; l++, y++) {
                        grid[x][y] = orig[k][l];
                    }
                }

                x = x-n+1; y=y+1;

            } else {
                int prev_y = y;
                for(int k=0 ; k<n; k++, x++) {
                    for(int l=0, y=prev_y; l<n; l++, y++) {
                        grid[x][y] = '.';
                    }
                }

                x = x-n+1; y=y+1;
            }

            if (y==n) {
                x = i + n;
                y = 0;
            }
        }   
    }

    print(grid);








}
