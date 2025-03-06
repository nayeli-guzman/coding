#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

void show_stack(stack<char> s) {
    stack<char> aux;
    while (!s.empty()) {
        cout << '\t' << s.top();
        aux.push(s.top());
        s.pop();
    }

    while (!aux.empty()) {
        s.push(aux.top());
        aux.pop();
    }

    cout << endl;
    
}

void back(int i, int n, stack<char> pila, queue<char> cola) {
    if(i==n) {
        show_stack(pila);
    }
    else {
        for (int j=i; j<n; j++) {
            pila.push(cola.front());
            cola.pop();

            //down to
            back(i+1, n, pila, cola);

            // get out an obj from stack
            cola.push(pila.top());
            pila.pop();
        }
    }
}

int main() {

    queue<char> cola;
    stack<char> pila;
    cola.push('a');
    cola.push('n');
    cola.push('r');

    int i=0;

    back(i, cola.size(), pila, cola);


    return 0;
}