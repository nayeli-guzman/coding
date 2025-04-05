#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

namespace std {
    template <> struct hash<pair<int, int>> {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };
}


void print(vector<int> v) {
    for(auto e:v) {
        cout << e << " ";
    } cout << endl;
}

bool comparison(pair<int, int> p1, pair<int, int> p2) {
    return p1.first < p2.first;
}

int maxFrequency(vector<int>& nums, int k, int numOperations) {

    unordered_map<int, int> hash;

    set<int> points;
    vector<pair<int, int>> events;
    vector<int> upper;

    for(int i=0; i<nums.size(); i++) {

        hash[nums[i]]++;

        events.push_back({nums[i]-k,1});
        events.push_back({nums[i]+k+1,-1});

        points.insert(nums[i]);
        points.insert(nums[i]+k+1);
        points.insert(nums[i]-k);

    }


    sort(events.begin(), events.end(), comparison);

    for(auto e:events) {
        cout << e.first << " " << e.second << endl;
    }

    int result=1, idx=0, count=0;

    for(auto point:points) {
        while(idx<events.size() && events[idx].first <= point) {
            count=count+events[idx++].second;
        }

        int curr_freq = hash.find(point)==hash.end()?0:hash[point];
        int res = curr_freq + min(numOperations, max(0,count-curr_freq));

        result = max(result, res);
    }


    return result;

}


int main() {

    vector<int> v={5,11,20,20};
    int k=5, n=1;

    cout << "result: " << maxFrequency(v,k,n) << endl;

    return 0;
}