#include <iostream>
#include <string>

using namespace std;

string defangIPaddr(string address) {

    string result = "";
    
    for (auto caracter : address) {
        if (caracter=='.') {
            result = result + "[.]";
        } else {
            result = result + caracter;
        }
    }

    return result;

}

int main() {

    cout << defangIPaddr("1.1.1.1") << endl;
    cout << defangIPaddr("255.100.50.0");

    return 0;
}