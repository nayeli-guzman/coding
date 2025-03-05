#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {


    vector<vector<int>> result;
    int idx1 = 0, idx2 = 0;

    cout << "KJNAKSJN";
    
    while (1) {

        if (idx1 >= nums1.size() || idx2 >= nums2.size())
            break;
        vector<int> temp;

        if (nums1[idx1][0] == nums2[idx2][0]) {
            cout << "KSSSSJNAKSJN";
            temp.push_back(nums1[idx1][0]);
            temp.push_back(nums1[idx1][1] + nums2[idx2][1]);
            idx1++; idx2++;
        } else if (nums1[idx1][0] < nums2[idx2][0]) {
            temp.push_back(nums1[idx1][0]);
            temp.push_back(nums1[idx1][1]);
            idx1++;
        } else {
            temp.push_back(nums2[idx2][0]);
            temp.push_back(nums2[idx2][1]);
            idx2++;
        }

        result.push_back(temp);
        

    }

    vector<vector<int>> temp = (idx1 >= nums1.size()?nums2:nums1);
    int idx = (idx1 >= nums1.size()?idx2:idx1);

    for (int i=idx; i<temp.size(); i++) {
        result.push_back(temp[i]);
    }

    return result;

}

void print(vector<vector<int>> vec) {
    for (const auto& vec : vec) {
        std::cout << "{" << vec[0] << "," << vec[1] << "} ";
    }
}

int main() {

    std::vector<std::vector<int>> nums1 = {{2, 4}, {3, 6}, {5, 5}};
    std::vector<std::vector<int>> nums2 = {{1, 3}, {4, 3}};

    // Imprimir los vectores
    std::cout << "nums1: ";
    print(nums1);

    std::cout << "\nnums2: ";
    print(nums2);
    std::cout << "\nRESS: ";
    print(mergeArrays(nums1, nums2));


    return 0;
}

