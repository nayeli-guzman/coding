#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> plusOne(vector<int>& digits) {

    int num=0, extra=0;
    
    for(int i=digits.size()-1; i>=0; i--) {
        int sum = (i==digits.size()-1 ? digits[i] + 1 + extra: digits[i]+extra);

        if (sum >= 10) {
            digits[i] = 0;
            if (i==0) {
                digits.insert(digits.begin(), 1);
                return digits;
            }
            extra = 1;
        } else {
            digits[i] = sum;
            return digits;
        }
    }

    return digits;
}

void print(vector<int> v) {
    for(auto e:v){
        cout << e << " ";
    }
}

int main() {

    vector<int> v = {9,9};

    print(plusOne(v));

    return 0;
}