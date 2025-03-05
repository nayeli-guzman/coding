#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {

    int k=0, i=0;
    // k: recorre los no repes
    // i: recorre all

    while(i+1< nums.size()){ 
        if(nums[k] == nums[i+1]) {
            if(++i<nums.size()) {
                if (i+1>=nums.size())
                    break;
                if (nums[k] != nums[i+1])
                    nums[++k] = nums[++i];
                
            }
        } else {
            nums[++k] = nums[++i];
        }
    }

    return k+1;

}

void print(vector<int> v) {
    for (auto e:v)
        cout << e << " ";
    cout << endl;
}

int main(){


    vector<int> v = {1,1,2};
    vector<int> v2 = {0,0,1,1,1,2,2,3,3,4};
    vector<int> v3 = {1,1};

    cout << removeDuplicates(v3)<<endl;
    print(v3);

    return 0;
}