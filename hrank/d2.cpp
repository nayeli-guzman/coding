#include <iostream>
#include <vector>
#include<unordered_set>
using namespace std;


bool backtrack(int idx, int mod, const vector<int>& nums, string expr, string& result, unordered_set<int>& visited) {
    if (idx == nums.size()) {
        if (mod == 0) {  
            result = expr;
            return true;
        }
        return false;
    }

    //if (visited.count(mod)) return false;
    //visited.insert(mod);

    int num = nums[idx];
    if (backtrack(idx + 1, (mod + num) % 101, nums, expr + "+" + to_string(num), result, visited)) return true;
    if (backtrack(idx + 1, (mod - num + 101) % 101, nums, expr + "-" + to_string(num), result, visited)) return true;
    if (backtrack(idx + 1, (mod * num) % 101, nums, expr + "*" + to_string(num), result, visited)) return true;

    return false;
}

string arithmeticExpressions(vector<int>& arr) {
    string result;
    unordered_set<int> visited;
    if (backtrack(1, arr[0] % 101, arr, to_string(arr[0]), result, visited))
        return result;
    return "No solution";
}

int main() {

    for (int i=0;i<100;i++){
        cout << i*101 << endl;
    }
    /*
    int n=0;
    vector<int> nums;

    cin >> n;

    for(int i=0;i<n;i++){
        int temp=0;
        cin >> temp;
        nums.push_back(temp);
    }
*/




    return 0;
}