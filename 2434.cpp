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
using sc = stack<char>;
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

string robotWithString(string s) {
    string temp;
    string ans;
    int n = s.size();   

    for(int i=0; i<n; i++) {
        char mini1 = s[i];
        for(int j=i; j<n; j++) {
            mini = min(mini, s[j]);
        }
        char mini2 = temp.size() > 0 ? temp.back() : 'A';
        for(int j=0; j<temp.size(); j++) {
            mini2 = min(mini2, temp[j]);
        }

        }
        if (s[i] != mini && mini2 > s[i]) {
            stack.push(s[i]);
            continue;
        } else {
            ans.push_back(s[i]);
        }
    }

    while (!stack.empty()) {
        char temp = stack.top();
        stack.pop();
        ans.push_back(temp);
    }
    return ans;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "mmuqezwmomeplrtskz";
    cout << robotWithString(s);

    return 0;
}