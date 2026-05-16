#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <climits>
using namespace std;

using vi = vector<int>;

bool debug = 0;
int n;
int t;
vi nums;

void print(vi v) {
    for (int i=0; i<v.size(); i++) {
        if (i==v.size()-1) cout << v[i];
        else cout << v[i] << "+";
    } cout << endl;
}

void back(int beg, vi ans, int temp, bool&conf) {

    if (nums[beg]>temp) {
        return;
    }

    ans.push_back(nums[beg]);
    temp = temp - nums[beg];

    if (temp==0) {
        conf=1;
        print(ans);
        return;
    }

    for (int i=beg+1;i<t;i++) {
        if (i > beg + 1 && nums[i] == nums[i - 1]) continue;
        back(i,ans,temp, conf);
    }
}


int main() {


    while (cin>>n>>t) {
        bool conf = 0;
        if(n==0) return 0;
        cout << "Sums of " << n << ":" << endl;
        nums.assign(t,0);

        for (int i=0;i<t;i++) {
            cin>>nums[i];
        }

        vi ans;
        for (int i=0;i<t;i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            back(i, ans, n, conf);
        }
        if(!conf) cout << "NONE" << endl;
    }

    

    return 0;
}
