#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;
using vii = vector<vi>;
using vb = vector<bool>;
using vbb = vector<vb>;
using vc = vector <char>;
using vcc = vector<vc>;

bool debug = 0;

int C = 8;
vcc chess(C, vc(8,'.'));

vb cols(C,0);
vb diag(2*C-1, 0); // i-j + C - 1
vb contdiag(2*C-1, 0); // I+J

int T=0;

bool back(int i) {

    if (i==C) {
        T++;
        if (debug) cout << "UNA SOLU MAS" << endl;
        return true;
    }

    for (int j=0; j<C; j++) {
        if (chess[i][j] == '*') continue;


        if (!cols[j] && !diag[i-j+C-1] && !contdiag[i+j]) {
            if (debug) cout << "i=" << i << " j=" << j << endl;
            cols[j] = 1;
            diag[i-j+C-1] = 1;
            contdiag[i+j] = 1;
            bool r = back(i+1);
            cols[j] = 0;
            diag[i-j+C-1] = 0;
            contdiag[i+j] = 0;
        }
    }
    return false;
}

int main() {
    if (debug) cout << "  ";
    if (debug) for (int i=0; i<C; i++) {cout << i << " ";}
    if (debug) cout << endl;

    for (int i=0; i<C; i++) { if (debug) cout << i << " ";
        for (int j=0; j<C; j++) {
            cin>>chess[i][j];
            if (debug) cout <<chess[i][j] << " ";
        } if (debug) cout << endl;
    }


    
    back(0);
    

    cout << T << endl;




    return 0;
}