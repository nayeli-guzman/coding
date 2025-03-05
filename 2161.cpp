#include <iostream>
#include <vector>
using namespace std;

vector<int> pivotArray(vector<int>& nums, int pivot) {
    vector<int> v1, v2, v3;
    
    for (auto e:nums) {
        if (e<pivot)
            v1.push_back(e);
        else if (e>pivot)
            v2.push_back(e);
        else v3.push_back(pivot);
    }

    v1.insert(v1.end(), v3.begin(), v3.end());
    v1.insert(v1.end(), v2.begin(), v2.end());
    return v1;
}


int main() {



    return 0;
}