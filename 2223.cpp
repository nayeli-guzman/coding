//z - algorithm

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

long long z_function(string s) {
    long long n = s.size();
    vector<long long> z(n,0);
    long long l = 0, r = 0;
    for(long long i = 1; i < n; i++) {
        if(i < r) {
            z[i] = std::min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return accumulate(z.begin(), z.end(), 0);
}

long long sumScores(string s) {
    return z_function(s) + s.size();
}

int main() {
    string s = "babab";
    cout << sumScores(s) ;

    return 0;
}