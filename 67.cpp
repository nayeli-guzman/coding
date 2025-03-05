#include <iostream>
#include <vector>
using namespace std;

string addBinary(string a, string b) {
    
    int as = a.size()-1, bs = b.size()-1;
    char extra = '0';
    string result = "";


    while(as>=0 && bs>=0) {
        if ((a[as]=='1' && b[bs]=='1' && extra == '0') ||
            a[as]=='0' && b[bs]=='1' && extra == '1' ||
            a[as]=='1' && b[bs]=='0' && extra == '1'
        ) {
            result = '0' + result;
            extra = '1';
        }
        else if ((a[as]=='1' && b[bs]=='1' && extra == '1')) {
            result = '1' + result;
            extra = '1';
        } else if ((a[as]=='0' && b[bs]=='1' && extra == '0') ||
            (a[as]=='1' && b[bs]=='0' && extra == '0') ||
            (a[as]=='0' && b[bs]=='0' && extra == '1')) {
                result = '1' + result;
                extra = '0';
            }
        else {
            result = '0' + result;
            extra = '0';
        }

    
        as--; bs--;
    }

    int min = (as<0?bs:as);
    string miss = (as<0?b:a);

    cout << miss << endl;

    while(min>=0) {
        if(miss[min] == '1' && extra=='1') {
            extra = '1';
            result = '0' + result;
        }
        else if(miss[min] == '0' && extra=='0') {
            extra = '0';
            result = '0' + result;
        } else {
            extra = '0';
            result = '1' + result;
        }
        min--;
    }
    

    result = (extra=='1'? '1'+result:result);

    return result;
}

int main() {

    string a = "110010", b = "100";

    cout << addBinary(a,b);



    return 0;
}