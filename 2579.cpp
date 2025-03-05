#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long coloredCells(int n) {
    
    if(n==1) return 1;
    return 2*(pow(n,2)-n)+1; // solving the recurrence
}

int main(){

    cout << coloredCells(1);

    return  0;
}