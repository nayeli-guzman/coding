#include <iostream>

using namespace std;

void print(vector<vector<int>> vectors){
    for(auto vector:vectors){
        for(auto element:vector)
            cout << element << " ";
        cout << endl;
    }
    cout << endl;
}

void print(vector<int> vector){
    for(auto element:vector)
        cout << element << " ";
    cout << endl;
}

void backtrancking(vector<int> candidates
                    , int target
                    , vector<vector<int> > &result
                    , vector<int> prev
){
    if(target==0){
        print(prev);
        return;
    } else {
        for (auto num:candidates) {
            if(num > target) {
                return;
            }
            prev.push_back(num);
            backtrancking(candidates,target-num,result,prev);
            prev.pop_back();
        }       
    }

}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

    vector<vector<int>> result;
    vector<int> prev;
    backtrancking(candidates, target,result,prev);
    print(result);
    return result; // reuslt has repes as 223 != 322 != 232

}

int main(){

    vector<int> nums = {2,3,5};
    int target = 8;
    combinationSum(nums, target);

    return 0;
}