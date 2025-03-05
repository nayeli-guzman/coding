#include <iostream>
#include <vector>
using namespace std;

int binary_search(int l, int r, vector<int> v, int target) {

    if(r<l) return 0;

    if(r==l) {
        if(v[r]>=target)
            return r;
        return r+1;
    }
    int m = (l+r)/2+1;
    cout << m << endl;

    if (target == v[m])
        return m;
    else if (target < v[m]) {
       return binary_search(l,m-1,v,target);
    } else {
        return binary_search(m+1,r,v,target);
    }

}

int searchInsert(vector<int>& nums, int target) {
    return binary_search(0,nums.size()-1,nums,target);
}

int main() {

    vector<int> v = {1};
    int target = 1;

    cout << searchInsert(v, target);

    return 0;
}