#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool aux(int n, vector<int>&v) {

    int sum=0, last=0;

    for (int i=0; i<=v.size(); i++) {
        sum = sum + pow(3,i);
        
        if (sum==n && v[i]!=-1)
            return true;
        else if (sum==n && v[i]==-1)
            return false;
        else if (sum>n) {
            if(pow(3,i)==n && v[i]!=-1) return true;
            if(pow(3,i)==n && v[i]==-1) return false;

            last = pow(3,i)<n? i: i-1;
            if(v[last]==-1) return false;
            v[last]=-1;
            int res = n-pow(3,last);
            return aux(res,v);
        }
    }

    return false;

}

bool checkPowersOfThree(int n) {

    int sum=0, last=0;
    vector<int> pows;
    
    for (int i=0; i<=n; i++) {
        sum = sum + pow(3,i);
        pows.push_back(i);

        if (sum==n)
            return true;
        else if (sum>n) {
            if(pow(3,i)==n) return true;
            last = pow(3,i)<n? i: i-1;
            pows[last]=-1;
            int res = n-pow(3,last);
            return aux(res, pows);
        }

    }
    return false;

}

int main() {

    cout << checkPowersOfThree(11);

    return 0;
}