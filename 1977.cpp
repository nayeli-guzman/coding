#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int numberOfCombinations(string num) {
    int n = num.size();
    if (num[0] == '0') return 0; // ningún número puede empezar con 0

    vector<vector<int>> sumi(n + 1, vector<int>(n + 1, 0)); 
    vector<vector<int>> lcp(n + 1, vector<int>(n + 1, 0)); 

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (num[i] == num[j]) {
                lcp[i][j] = 1 + lcp[i + 1][j + 1];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int long1 = 1; long1 <= i + 1; long1++) {
            int j = i - long1 + 1;
            int curr = 0;

            if (num[j] == '0') {
                curr = 0;
            } else if (j == 0) {
                curr = 1;
            } else {
                int long2;
                if (j < long1) {
                    long2 = j;
                } else {
                    int temp = lcp[j - long1][j];
                    if (temp >= long1 || num[j - long1 + temp] <= num[j + temp]) {
                        long2 = long1;
                    } else {
                        long2 = long1 - 1;
                    } 
                }
                curr = sumi[j - 1][long2];
            }

            sumi[i][long1] = (sumi[i][long1 - 1] + curr) % MOD;
        }
    }

    return sumi[n - 1][n];
}

int main() {
    string s = "327";
    cout << numberOfCombinations(s) << endl;
    return 0;
}
