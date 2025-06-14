#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using umii = unordered_map<int, int>;
using usi = unordered_set<int>;
using vvi = vector<vi>;


void print(vi v) {
    for(auto e:v) cout<<e<<" "; cout<<endl;
}

void print(usi s) {
    for(auto e:s) cout<<e<<" "; cout<<endl;
}

void print(vvi m) {
    for(auto v:m) print(v); cout << endl;
}

int lengthOfLIS(vi v) {
    int n = v.size();
    vi dp(n,0);
    dp[n-1] = 1;
    for(int i=n-2; i>=0; i--) {
        int maxi = INT32_MIN;
        for(int k=i+1; k<n; k++) {
            if(v[i]<v[k]) {
                maxi = max(maxi,dp[k]);
            }
        }
        if(maxi==INT32_MIN) {
            dp[i] = 1;
        } else {
            dp[i] = maxi + 1;
        }
    }

    int res = dp[0];
    for(auto e:dp) {
        res = max(res, e);
    }
    return res;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vi v = {10,9,2,5,3,7,101,18};
    cout << lengthOfLIS(v);

    return 0;
}