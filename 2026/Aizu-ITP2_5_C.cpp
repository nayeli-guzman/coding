#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

using vi = vector<int>;

int n;
vi nums;

void print(vi v) {
    for (int i=0; i<n; i++) {
        if (i==n-1) cout << v[i];
        else cout << v[i] << " ";
    } cout << endl;
}

bool is_sorted(vi v) {
    for (int i=0; i<n-1; i++) {
        if (v[i]<v[i+1]) continue;
        return 0;
    }
    return 1;
}

bool is_antisorted(vi v) {
    for (int i=0; i<n-1; i++) {
        if (v[i]>v[i+1]) continue;
        return 0;
    }
    return 1;
}

vi maxi(vi num) {

    int ans = INT32_MAX;
    
    for (int i=n-1; i>=0; i--) {
        if (num[i]<num[i-1]) continue;
        int m = num[i-1], id_m = -1;
        for (int j=i;j<n;j++) {
            if (num[j] > m && num[j] < ans) {
                ans = num[j];
                id_m = j;
            }
        }
        swap(num[i-1], num[id_m]);
        sort(num.begin()+i, num.end());
        break;
    }
    return num;
}

vi mini(vi num) {

    int ans = INT32_MIN;
    
    for (int i=n-1; i>=0; i--) {
        if (num[i]>num[i-1]) continue;
        int m = num[i-1], id_m = -1;
        for (int j=i;j<n;j++) {
            if (num[j] < m && num[j] > ans) {
                ans = num[j];
                id_m = j;
            }
        }
        swap(num[i-1], num[id_m]);
        sort(num.begin()+i, num.end(), greater<>());
        break;
    }
    return num;
}



int main() {

    cin>>n;
    nums.assign(n, 0);
    for (int i=0; i<n; i++) {
        cin>>nums[i];
    }

    if (n==1) {
        cout << n << endl; return 0;
    }

    bool next=0, prev=0;

    if (nums[n-1] > nums[n-2]) next=1;
    else prev=1;

    if (prev) {
        swap(nums[n-1], nums[n-2]);
        print(nums);
        swap(nums[n-1], nums[n-2]);
        print(nums);
        if (is_antisorted(nums)) return 0;
        print(maxi(nums));
    } else {
        if (!is_sorted(nums)) print(mini(nums));
        print(nums);
        swap(nums[n-1], nums[n-2]);
        print(nums);
    }

    
    

    // swap the last 2 terms


    return 0;
}
