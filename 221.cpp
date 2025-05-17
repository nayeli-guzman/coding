#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

using i = int;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using umii = unordered_map<int, int>;
using usi = unordered_set<int>;
using vvc = vector<vector<char>>;
using vc = vector<char>;
using vvi = vector<vi>;

void print(vc v) {
    for(auto e:v)cout<<e<<" ";cout<<endl;
}
void print(usi s) {
    for(auto e:s)cout<<e<<" ";cout<<endl;
}
void print(vvc m) {
    for(auto e:m) {print(e);}cout<<endl;
}


int maximalSquare(vector<vector<char>>& grilla) {
    
    i m = grilla.size(), n = grilla[0].size();

    vvi res(m, vi(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = grilla[i][j] - '0';
        }
    }


    vvi dp(m, vi(n, 0));
    dp[m-1][n-1] = res[m-1][n-1];

    int maxi = 0;

    for(int i=m-1; i>=0; i--) {
        for(int j=n-1; j>=0; j--) {

            if(res[i][j]==0) continue;

            unsigned int a = INT32_MAX, b=INT32_MAX, c=INT32_MAX;
            bool conf = true;
            if(i+1<m) {
                conf = dp[i+1][j] != 0;
                a = dp[i+1][j];
            }
            if(j+1<n) {
                conf = dp[i][j+1] != 0;
                b = dp[i][j+1];
            }
            if(i+1<m && j+1<n) {
                conf = dp[i+1][j+1] != 0;
                c = dp[i+1][j+1];
            }
            if(conf && a!=INT32_MAX && b!=INT32_MAX && c!=INT32_MAX) { 
                dp[i][j] = min(min(a,b),c)+1;
                maxi = max(dp[i][j], maxi);
            } else {
                dp[i][j] = 1;
                maxi = max(dp[i][j], maxi);

            }            
        }
    }

    return maxi*maxi;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vvc matrix = {
    {'1','1','1','1'},
    {'1','1','1','1'},{'1','1','1','1'},
    {'1','1','1','1'}
};
    cout << maximalSquare(matrix);

    return 0;
}