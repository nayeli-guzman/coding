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

/*
states:

0. no cams
1. a cam
2. covered but not having a cam

*/


static constexpr int INF = 1000000;

    // returns {dp0, dp1, dp2} for subtree rooted at node:
    // dp0 = min cams if node is NOT covered
    // dp1 = min cams if node IS covered, but no cam at node
    // dp2 = min cams if there's a cam at node
std::array<int,3> dfs(TreeNode* node) {
    if (!node) return {0, 0, INF};

    auto L = dfs(node->left);
    auto R = dfs(node->right);

    int dp0 = L[1] + R[1];
    int dp2 = 1
        + std::min({L[0], L[1], L[2]})
        + std::min({R[0], R[1], R[2]});

    int coverByLeft  = L[2] + std::min(R[1], R[2]);
    int coverByRight = R[2] + std::min(L[1], L[2]);
    
    int dp1 = std::min(coverByLeft, coverByRight);
    return {dp0, dp1, dp2};
    
}

    int minCameraCover(TreeNode* root) {
        auto res = dfs(root);
        // root must be covered, either by its children or by itself
        return std::min(res[1], res[2]);
    }



int cams = 0;
unordered_map<TreeNode*, int> map;
void aux(TreeNode* node, TreeNode* parent) {
    if(node==nullptr) {
        map[node] = 2;
        return;
    }
    aux(node->left, node);
    aux(node->right, node);

    int left = map[node->left];
    int right = map[node->right];

    if(left==0 || right==0) {
        cams++;
        map[node] = 1;
    } 
    else if (left==1 || right==1) map[node] = 2;
    else map[node] = 0;
}

int minCameraCover(TreeNode* root) {
    aux(root, nullptr);
    if(map[root] == 0) {
        cams++; 
    }
    return cams;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}



