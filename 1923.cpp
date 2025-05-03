#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

const int BASE1 = 31, BASE2 = 37;
const int MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;

typedef pair<long long, long long> HashPair;

struct HashPairHash {
    size_t operator()(const HashPair& p) const {
        return hash<long long>()(p.first) ^ (hash<long long>()(p.second) << 1);
    }
};

unordered_set<HashPair, HashPairHash> get_hashes_from_vector(const vector<int>& vec, int k) {
    unordered_set<HashPair, HashPairHash> hashes;
    // vec: vector que queremos hashear
    if (vec.size() < k) return hashes;

    long long hash1 = 0, hash2 = 0;
    long long power1 = 1, power2 = 1;

    for (int i = 0; i < k; ++i) {
        hash1 = (hash1 * BASE1 + vec[i]) % MOD1;
        hash2 = (hash2 * BASE2 + vec[i]) % MOD2;
        if (i != k - 1) {
            power1 = (power1 * BASE1) % MOD1;
            power2 = (power2 * BASE2) % MOD2;
        }
    }

    hashes.insert({hash1, hash2});

    for (int i = k; i < vec.size(); ++i) {
        hash1 = (hash1 - vec[i - k] * power1 % MOD1 + MOD1) % MOD1;
        hash1 = (hash1 * BASE1 + vec[i]) % MOD1;

        hash2 = (hash2 - vec[i - k] * power2 % MOD2 + MOD2) % MOD2;
        hash2 = (hash2 * BASE2 + vec[i]) % MOD2;

        hashes.insert({hash1, hash2});
    }

    return hashes;
}

bool has_common_hash(int k, const vector<vector<int>>& paths) {
    
    unordered_set<HashPair, HashPairHash> common = get_hashes_from_vector(paths[0], k);

    for (int i = 1; i < paths.size(); ++i) {
        
        unordered_set<HashPair, HashPairHash> current = get_hashes_from_vector(paths[i], k);
        unordered_set<HashPair, HashPairHash> next_common;

        for (const auto& h : current) {
            if (common.count(h)) {
                next_common.insert(h); //insertar l aintersseción entre ambos
            }
        }

        common = move(next_common); // ahora solo se usan los elemntos intersecados
        if (common.empty()) return false; // si la intersección es vacia en al menos 1, signifa que no hay con ese k
    }

    return true;
}

int longestCommonSubpath(int n, vector<vector<int>>& paths) {
    int l = 0;
    int r = INT32_MAX;

    for (const auto& path : paths) {
        r = min(r, (int)path.size());
    }

    int answer = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;

        // se trbaja en el array mas pequeño y se hace busqueda binaria respecto a su size

        if (has_common_hash(mid, paths)) {
            answer = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> paths = {
        {1, 2, 0, 1},
        {2, 0},
        {2, 0},
        {1, 2},
        {0, 1, 0}
    };

    int result = longestCommonSubpath(paths.size(), paths);
    cout << "Longest common subpath length: " << result << endl;

    return 0;
}
