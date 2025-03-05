#include <iostream>
#include <vector>
using namespace std;

int lengthOfLastWord(string s) {

    string last="";

    for (int i=0;i<s.size();i++) {
        if(i+1<s.size() && s[i] == ' ' && s[i+1] != ' ') {
            last = "";
        } else if(s[i]==' ') {
            continue;
        }
        else {
            last = last + s[i];
        }
    }

    return last.size();

}

int main() {

    string s = "luffy is still joyboy";

    cout << lengthOfLastWord(s);

    return 0;
}