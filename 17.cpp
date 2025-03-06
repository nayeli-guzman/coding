#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

void backtracking(int idx
                    , string digits
                    , string result
                    , unordered_map<int, string> letters
                    , vector<string>&results
    ){
    
    if(idx==digits.size()) {
        results.push_back(result);
        return;
    } else {
        for (auto digit : letters[digits[idx]]) { // idx = 0
            result.push_back(digit);
            backtracking(idx+1, digits, result, letters, results);
            result.pop_back();
        }
    }

}

vector<string> letterCombinations(string digits) {

    if(digits.empty()) return {};

    unordered_map<int, string> hash{
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };

    string result = "";
    vector<string> results;

    backtracking(0, digits, result, hash, results);

    return results;

}

ostream&operator<<(ostream &os, const vector<string>& v) {
    for (auto e:v){
        os << e << endl;
    }

    return os;
}

int main(){

    string digits = "23";

    cout << letterCombinations(digits);

    return 0;
}







