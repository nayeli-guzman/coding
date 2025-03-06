#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// jeje, too expensive but works

void show_stack(stack<char> s, vector<int> nums, string& response) {
    int idx = nums.size()-1;
    response = to_string(nums[idx]);
    stack<char> aux;
    while (!s.empty()) {
        response = to_string(nums[--idx]) + s.top() + response;
        //cout << '\t' << s.top();
        aux.push(s.top());
        s.pop();
    }
    //cout << response << endl;
    while (!aux.empty()) {
        s.push(aux.top());
        aux.pop();
    }

    //cout << endl;

    //return total;
    
}

void back(int i
            , int n
            , stack<char> pila
            , vector<char> signs
            , vector<int> nums
            , int result // inicially result = v[0]
            , int idx
            , string &response
    ) {

    //cout << "i: " << i << endl;
    //cout << "n: " << n << endl;

    if (result<0) return;

    if(i==n) {
        //show_stack(pila, nums, response);
        
        if(result%101==0) {
            cout << result << endl;
            show_stack(pila, nums, response);
        }
        return;

    }
    else {

        for (auto sign:signs) {

            if (sign == '+')
                result = result + nums[idx];
            else if (sign == '-')
                result = result - nums[idx];
            else if (sign == '*')
                result = result * nums[idx];

            //cout << result << endl;

            pila.push(sign);

            //down to
            back(i+1, n, pila, signs, nums, result, idx+1, response);

            if (sign == '+')
                result = result - nums[idx];
            else if (sign == '-')
                result = result + nums[idx];
            else if (sign == '*')
                result = result / nums[idx];

            // get out an obj from stack
            pila.pop();
        }
    }
    
}


string arithmeticExpressions(vector<int> arr) {
    
    stack<char> pila;
    vector<char> signs = {'+', '-', '*'};
    string result = "";

    int i=0;

    back(i, arr.size()-1, pila, signs, arr, arr[0], 1, result);
    return result;
}

int main() {


    std::vector<int> arr = {63, 71, 78, 53, 49, 56, 55, 66, 73, 47, 35, 45, 9, 74, 5, 71, 48, 86, 11, 16, 91, 38, 94, 65, 53, 58, 6, 63, 27, 11, 63, 91, 42, 21, 46, 85, 31, 53, 10, 34, 27, 19, 96, 84, 95, 8, 31, 86, 83, 78, 36, 17, 18, 51, 98, 52, 50, 46, 30, 65, 20, 52, 17, 41, 26, 15, 73, 47, 61, 21, 80, 45, 62, 75, 26, 52, 100, 36, 100, 30, 55, 73, 5, 50, 96, 26, 54, 96, 28, 53, 73, 91, 58, 39, 40, 67, 85, 79, 95, 94, 60, 99, 3, 7, 28, 59, 32, 35, 50, 1, 89, 78, 62, 8, 45, 32, 80, 17, 78, 35, 85, 51, 74, 80, 82, 88, 42, 52, 67, 85, 24, 17, 25, 92, 2, 52, 33, 30, 42, 20, 91, 82, 10, 61, 15, 70};
    //vector<int> arr = {55,3,45,33,25};
    cout << arithmeticExpressions(arr);


    return 0;
}