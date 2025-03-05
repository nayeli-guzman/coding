#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string p1(int L, int L1, int L2) {

    if (L >= L1 && L <= L2) {
        return "Adecuado";
    } else {
        return "Inadecuado";
    }
}

string p2(int N, int T, vector<int> L) {

    int cont1 = 0;
    int cont2 = 0;

    for (int i=0; i<N; i++) {
        if (L[i] < T) {
            cont1++;
        } else if (L[i] == T) {
            cont2++;
        }
    }

    return to_string(cont1) + " " + to_string(cont2) ;

}

string p3(vector<int> A, vector<int> B) {
    
    int contA=0, contB=0;

    for (int i=0; i<3; i++) {
        if (A[i] > B[i]) {
            contA++;
        } else if (A[i] < B[i]) {
            contB++;
        }
    }

    if (contA > contB) {
        return "Krejcikova";
    } else {
        return "Paolini";
    }

}  
int main() {

/* Problema 1
    int L, L1, L2;
    cin >> L >> L1 >> L2;
    cout << p1(L, L1, L2);
*/

/* Problema 2
    int N, T;

    cin >> N >> T;

    vector<int> L;

    for (int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        L.push_back(temp);
    }

    cout << p2(N, T, L);
*/

/* Problema 3
    vector<int> A, B;

    for(int i=0; i<3; i++) {
        int temp; cin >> temp;
        A.push_back(temp);
    }

    for(int i=0; i<3; i++) {
        int temp; cin >> temp;
        B.push_back(temp);
    }

    cout << p3(A, B);

*/

/* Problema 4
    int N;
    cin >> N;

    map<string, vector<int>> paises;
    // 0:oro 1:plata 2:bronce

    for (int i=0; i<N; i++) {
        
        string pais, tipo;
        cin >> pais;
        cin >> tipo;

        int idx = (tipo=="oro")*0 + (tipo=="plata")*1 + (tipo=="bronce")*2;

        if (paises.find(pais) == paises.end()) {
            paises[pais] = vector<int>(3, 0);
        }
        
        paises[pais][idx]++;

    }

    for (auto it=paises.begin(); it!=paises.end(); it++) {
        cout << it->first << " " << it->second[0] << " " << it->second[1] << " " << it->second[2] << endl;
    }
*/


    int N, K;
    vector<int> L;
    cin >> N >> K;

    for (int i=0; i<N; i++) {
        int last, now;
        cin >> last >> now;
        L.push_back(last-now);
    }

    sort(L.begin(), L.end());
    reverse(L.begin(), L.end());

    cout << (L[K-1]);

    return 0;
}

// to generate te executable we need to put:
// g++ p1.cpp -o <name>


/*
std::sort(elementos.begin(), elementos.end(),
              [](const auto& a, const auto& b) {
                  return a.second < b.second; // Comparación por el valor
              });
*/