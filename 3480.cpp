#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
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
using vll = vector<ll>;
using pll = pair<ll, int>;
using vpll = vector<pll>;

Node combine(const Node& left, const Node& right) {
    Node parent;
    parent.sum = left.sum + right.sum;
    parent.prefixSum = max(left.prefixSum, left.sum + right.prefixSum);
    parent.suffixSum = max(right.suffixSum, right.sum + left.suffixSum);
    parent.maxSum = max({left.maxSum, right.maxSum, left.suffixSum + right.prefixSum});
    return parent;
}


struct Node {
    int sum;        // suma total del intervalo
    int prefixSum;  // mejor suma de prefijo
    int suffixSum;  // mejor suma de sufijo
    int maxSum;     // mejor suma total de subarreglo contiguo

    Node(): sum(0), prefixSum(0), suffixSum(0), maxSum(0) {}
    Node(int val): sum(val), prefixSum(val), suffixSum(val), maxSum(val) {}
};

class SegmentTree {
    vector<Node> tree;
    int n;

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, arr);
    }

    void build(int node, int l, int r, const vector<int>& arr) {
        if (l == r) {
            tree[node] = Node(arr[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, arr);
        build(2 * node + 1, mid + 1, r, arr);
        tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return Node(INT_MIN); // caso fuera de rango
        if (ql <= l && r <= qr) return tree[node];

        int mid = (l + r) / 2;
        Node left = query(2 * node, l, mid, ql, qr);
        Node right = query(2 * node + 1, mid + 1, r, ql, qr);

        if (left.sum == INT_MIN) return right;
        if (right.sum == INT_MIN) return left;

        return combine(left, right);
    }

    int getMaxSum(int l, int r) {
        return query(1, 0, n - 1, l, r).maxSum;
    }
};

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    SegmentTree st(arr);
    cout << st.getMaxSum(0, arr.size() - 1) << endl; // Output: 6 (subarray [4,-1,2,1])
    return 0;
}
