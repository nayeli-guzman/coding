#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

using vi = vector<int>;

int n;
vi nums;
bool debug = 0;

void print(vi v) {
    for (int i=0; i<n; i++) {
        if (i==n-1) cout << v[i];
        else cout << v[i] << " ";
    } cout << endl;
}

bool is_antisorted(vi v) {
    for (int i=0; i<n-1; i++) {
        if (v[i]>v[i+1]) continue;
        return 0;
    }
    return 1;
}

void maxi(vi num) {

    
    for (int i=n-1; i>=0; i--) {

        if (debug) cout << "i:" << i << endl;

        if (num[i]<num[i-1]) continue;
        
        int ans = INT32_MAX;

        int m = num[i-1], id_m = -1;
        for (int j=i;j<n;j++) {
            if (num[j] > m && num[j] < ans) {
                ans = num[j];
                id_m = j;
            }
        }
        swap(num[i-1], num[id_m]);
        sort(num.begin()+i, num.end());
        print(num);
        i=n;
        if (debug) cout <<  endl;

        if (is_antisorted(num)) break;
    }
}



int main() {

    cin>>n;
    nums.assign(n, 0);
    for (int i=0; i<n; i++) {
        nums[i]=i+1;
    }

    if (n==1) {
        cout << n << endl; return 0;
    }


    print(nums);

    maxi(nums);

    return 0;
}
