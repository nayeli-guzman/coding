#include <iostream>
#include <vector>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    vector<int> result(2);
    int n = grid.size();
    vector<int> nums(n*n, -1);

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int idx = grid[i][j];
            if (nums[idx-1] != -1) {
                result[0] = idx;
            }
            else nums[idx-1] = idx;
        }
    }

    for (int i=0; i<nums.size();i++)
        if(nums[i]==-1) {
            result[1] = i+1;
            break;
        }

    return result;
}

ostream &operator<<(ostream& os, const vector<int>& v ){
    for (auto e:v){
        os << e << " ";
    }
    os << endl;
    return os;
}

int main(){

    vector<vector<int>> v = {{9,1,7},{8,9,2},{3,4,6}};

    cout << findMissingAndRepeatedValues(v);

    return 0;
}