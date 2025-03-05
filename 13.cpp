#include <iostream>
#include <unordered_map>
using namespace std;

int romanToInt(string s) {
       
    unordered_map<char, int> letters = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int a=0;
    int i=s.size()-1;

    while (i>=0){
        if(i-1>=0 && letters[s[i]]> letters[s[i-1]]) {
            a =  a + (letters[s[i]] - letters[s[--i]]);
        }
        else
            a = a + letters[s[i]];
        i--;
    }
    return a;
}

int main(){

    cout << romanToInt("LVIII");
    return 0;
}