#include <iostream>
#include <vector>

using namespace std;


int removeElement(vector<int>& nums, int val) {
    int i=0, k=0;

    while(i+1<= nums.size()){ 
        if(nums[i]==val) {
            i++;

        } else {
            nums[k++] = nums[i++];
        }
    }
    return k;

}


void print(vector<int> v) {
    for (auto e:v)
        cout << e << " ";
    cout << endl;
}

int main(){


    vector<int> v = {3,2,2,3};
    vector<int> v2 = {0,1,2,2,3,0,4,2};

    cout << removeElement(v2, 2) <<endl;
    print(v2);

    return 0;
}