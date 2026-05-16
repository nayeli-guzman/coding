#include <iostream>
#include <cmath>

using namespace std;

using ll = long long;
using ld = long double;
const ld EPS = 1e-18L;

inline bool ok(ll m, ld h1, ld h2, ld q){
    return h1 * pow(q, (ld)m) <= h2;
}

int main()
{
    int k;
    cin>>k;

    while(k-->0)
    {
        ld h1, h2;
        ll b;
        cin>>h1>>h2>>b;

        ld q = 1.0L - 1.0L / (ld)b;

        ll l=0,r=1;
        while (!ok(r, h1, h2, q)) {
            r = r << 1;                  
        }

        ll m;

        while (l<r){

            m = (l+r) >> 1;

            if (ok(m, h1, h2, q)) 
            {
                r = m;
            } 
            else 
            {
                l = m + 1;
            }
        }


        cout << l << endl;

    }

    return 0;
}