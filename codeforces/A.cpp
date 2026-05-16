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
using vvi = vector<vi>;
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


vi pre(vi pattern) {
    int m = pattern.size();
    vi p(m, 0);
    int k = 0;

    for (int i = 1; i < m; i++) {
        while (k > 0 && pattern[i] != pattern[k]) k = p[k - 1];
        if (pattern[i] == pattern[k]) k++;
        p[i] = k;
    }
    return p;
}

int solve(vi A, vi B) {
    if (B.empty()) return A.size() + 1;
    
    int n = A.size(), m = B.size();

    vi p = pre(B);
    int ans = 0, k = 0;

    for (int i = 0; i < n; i++) {
        while (k > 0 && A[i] != B[k]) k = p[k - 1];
        if (A[i] == B[k]) k++;
        if (k == m) {
            ans++;
            k = p[k - 1];
        }
    }

    return ans;
}

int main() {
    int n, w;
    cin >> n >> w;
    vi a(n), b(w);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < w; i++) cin >> b[i];

    if (w == 1) {
        cout << n << endl;
        return 0;
    }

    vi A(n - 1), B(w - 1);
    for (int i = 0; i < n - 1; i++) 
        A[i] = a[i + 1] - a[i];
    
    for (int i = 0; i < w - 1; i++) 
        B[i] = b[i + 1] - b[i];

    cout << solve(A, B) << endl;

    return 0;
}
