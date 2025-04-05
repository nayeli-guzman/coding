#include <iostream>
#include <algorithm>
using namespace std;

int minimumDifference(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int i=0, j=nums.size()-1; 
    int s1=0, s2=0;
    while (i<=j){

        if(nums[i]<0) {

        } else {
            s1=s1+nums[i++]+nums[j--];
            s2=s2+nums[i++]+nums[j--];
        }
    }

    return abs(s1-s2);
}

int main(){



    return 0;
}