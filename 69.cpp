#include <iostream>
#include <vector>
using namespace std;

int mySqrt(int x) {

    if(x==0) return 0;
    if(x==1) return 1;
    
    for (int i=0; i<=x; i++) {
        if (i*i == x)
            return i;
        else if (i*i>x)
            return i-1;
    }

    return 0;

}

int main() {



    return 0;
}