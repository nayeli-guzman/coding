#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {

    stack<char> open;
    
    for (auto car:s) {
        if (car=='{' || car=='[' || car=='(') {
            open.push(car); //push_back
        } else {

            if (open.empty()) return false;

            if (open.top()=='{' && car=='}')
                open.pop(); // pop_back
            else if (open.top()=='[' && car==']')
                open.pop();
            else if (open.top()=='(' && car==')')
                open.pop();
            else return false;
        }
    }

    if(!open.empty())
        return false; 

    return true;

}

int main(){

    cout << isValid("{}") << endl;
    cout << isValid("()[]{}") << endl;
    cout << isValid("(])") << endl;
    cout << isValid("([])") << endl;

    return 0;
}