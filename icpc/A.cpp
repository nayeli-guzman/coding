#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;


int main() {

    int n; 
    cin >> n;
    vi v(n);

    int suma =0;

    for (int i=0; i<n; i++ )
    {
        cin>>v[i];
        suma = suma + v[i];
    }

    int cont = 0;

    while (suma%n-- != 0)
    {
        cont++;
    }

    cout << cont;





    return 0;
}
